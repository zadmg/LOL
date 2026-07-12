"""
完整解析 Pikachu 自建证书链 + Thawte 代码签名证书
综合使用 asn1crypto + cryptography 库进行深度解析
"""
import os
import struct
import hashlib
from datetime import datetime

SRC = r"D:\SRC\SRC"
OUTPUT = os.path.join(SRC, "buried_data", "cert_full_analysis.txt")

# ============================================================
# OID 名称映射
# ============================================================
OID_NAMES = {
    "1.2.840.113549.1.9.1": "emailAddress",
    "2.5.4.3": "CN",
    "2.5.4.6": "C",
    "2.5.4.7": "L",
    "2.5.4.8": "ST",
    "2.5.4.10": "O",
    "2.5.4.11": "OU",
    "2.5.4.12": "title",
    "2.5.4.5": "serialNumber",
    "2.5.4.13": "description",
    "1.2.840.113549.1.1.1": "rsaEncryption",
    "1.2.840.113549.1.1.5": "sha1WithRSAEncryption",
    "1.2.840.113549.1.1.11": "sha256WithRSAEncryption",
    "1.2.840.113549.1.1.4": "md5WithRSAEncryption",
    "2.5.29.19": "basicConstraints",
    "2.5.29.15": "keyUsage",
    "2.5.29.37": "extKeyUsage",
    "2.5.29.17": "subjectAltName",
    "2.5.29.14": "subjectKeyIdentifier",
    "2.5.29.35": "authorityKeyIdentifier",
    "2.5.29.31": "cRLDistributionPoints",
    "2.5.29.32": "certificatePolicies",
    "2.5.29.9": "subjectDirectoryAttributes",
    "1.3.6.1.5.5.7.3.1": "serverAuth",
    "1.3.6.1.5.5.7.3.2": "clientAuth",
    "1.3.6.1.5.5.7.3.3": "codeSigning",
    "1.3.6.1.5.5.7.3.4": "emailProtection",
    "1.3.6.1.5.5.7.3.8": "timeStamping",
    "1.3.6.1.5.5.7.48.1": "OCSP",
    "1.3.6.1.5.5.7.48.2": "CA Issuers",
    "1.3.6.1.4.1.311.3.3.1": "szOID_NESTED_SIGNATURE",
    "1.3.6.1.4.1.311.2.1.12": "spc_sp_opus_info",
    "1.3.6.1.4.1.311.2.1.11": "spc_statement_type",
    "1.3.6.1.4.1.311.2.1.10": "spc_individual_sp_key_purpose",
    "1.2.840.113549.1.9.3": "contentType",
    "1.2.840.113549.1.9.4": "messageDigest",
    "1.2.840.113549.1.7.2": "signedData",
    "1.2.840.113549.1.7.1": "data",
}

def oid_name(oid_str):
    return OID_NAMES.get(oid_str, oid_str)

# ============================================================
# 1. 加载数据
# ============================================================
with open(os.path.join(SRC, "enhr_embedded", "enhr_outer.exe"), "rb") as f:
    full_data = f.read()

# 读取 ASN.1 长度
def read_asn1_len(data, off):
    b = data[off]
    if b & 0x80:
        n = b & 0x7f
        return int.from_bytes(data[off+1:off+1+n], 'big'), 1+n
    return b, 1

# 提取 Thawte PKCS#7 (标准格式)
hdr_size1 = struct.unpack_from("<I", full_data, 0xD3F0)[0]
thawte_pkcs7_1 = full_data[0xD3F0 + 8:0xD3F0 + 8 + hdr_size1]

hdr_size2 = struct.unpack_from("<I", full_data, 0x16BD0)[0]
thawte_pkcs7_2 = full_data[0x16BD0 + 8:0x16BD0 + 8 + hdr_size2]

# 提取 Pikachu PKCS#7 内部 signedData
# 外层结构: SEQUENCE { OID(1.3.6.1.4.1.311.3.3.1), SET { SEQUENCE { signedData } } }
# 内层 signedData 在 gap 区的 0xE49A, 在 PE2 后区的 0x17C7A
def extract_inner_signeddata(offset):
    off = offset
    tag = full_data[off]; off += 1
    length, lb = read_asn1_len(full_data, off); off += lb
    tag = full_data[off]; off += 1
    oid_len, lb = read_asn1_len(full_data, off); off += lb
    off += oid_len
    tag = full_data[off]; off += 1
    set_len, lb = read_asn1_len(full_data, off); off += lb
    tag = full_data[off]; off += 1
    inner_len, lb = read_asn1_len(full_data, off); off += lb
    inner_start = off - 1 - lb
    return full_data[inner_start:inner_start+1+lb+inner_len]

pikachu_signed_1 = full_data[0xE49A:0xE49A+struct.unpack_from(">H", full_data, 0xE49A+2)[0]+4]
pikachu_signed_2 = full_data[0x17C7A:0x17C7A+struct.unpack_from(">H", full_data, 0x17C7A+2)[0]+4]

print(f"Thawte PKCS#7 #1: {len(thawte_pkcs7_1)} bytes")
print(f"Thawte PKCS#7 #2: {len(thawte_pkcs7_2)} bytes")
print(f"Pikachu signedData #1: {len(pikachu_signed_1)} bytes at 0xE49A")
print(f"Pikachu signedData #2: {len(pikachu_signed_2)} bytes at 0x17C7A")

# ============================================================
# 2. 使用 asn1crypto 解析所有证书
# ============================================================
from asn1crypto import cms, x509 as asn1_x509
from cryptography import x509 as crypto_x509
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.serialization import pkcs7, Encoding

all_certs = []  # 所有证书信息 (带重复)
all_blocks = []  # PKCS#7 块信息

def format_rdn(name_obj):
    if name_obj is None:
        return "(empty)"
    try:
        return name_obj.human_friendly
    except:
        try:
            n = name_obj.native
            if isinstance(n, dict):
                return ", ".join(f"{oid_name(k)}={v}" for k, v in n.items())
            return str(n)
        except:
            return str(name_obj)

def extract_cert_info(cert_der, cert_idx, source):
    """使用 cryptography 库提取证书信息"""
    cert = crypto_x509.load_der_x509_certificate(cert_der)
    info = {}
    info['index'] = cert_idx
    info['source'] = source
    
    # 基础信息
    info['subject'] = cert.subject.rfc4514_string()
    info['issuer'] = cert.issuer.rfc4514_string()
    info['serial'] = cert.serial_number
    
    # 有效期
    info['not_before'] = cert.not_valid_before_utc
    info['not_after'] = cert.not_valid_after_utc
    
    # 签名算法
    sig_oid = cert.signature_algorithm_oid
    info['sig_algo'] = sig_oid._name if sig_oid else "unknown"
    
    # 公钥
    pubkey = cert.public_key()
    algo_name = type(pubkey).__name__
    algo_name = algo_name.replace('RSAPublicKey', 'RSA').replace('ECPublicKey', 'EC').replace('DSAPublicKey', 'DSA').replace('Ed25519PublicKey', 'Ed25519').replace('Ed448PublicKey', 'Ed448')
    info['pubkey_algo'] = algo_name
    try:
        info['pubkey_size'] = pubkey.key_size
    except:
        info['pubkey_size'] = "unknown"
    
    # 指纹
    info['sha1'] = hashlib.sha1(cert_der).hexdigest().upper()
    info['sha256'] = hashlib.sha256(cert_der).hexdigest().upper()
    
    # 是否自签名
    info['self_signed'] = (info['subject'] == info['issuer'])
    
    # 扩展字段
    def get_ku_names(ku):
        names = []
        if ku.digital_signature: names.append("digital_signature")
        if ku.content_commitment: names.append("content_commitment")
        if ku.key_encipherment: names.append("key_encipherment")
        if ku.data_encipherment: names.append("data_encipherment")
        if ku.key_agreement: names.append("key_agreement")
        if ku.key_cert_sign: names.append("key_cert_sign")
        if ku.crl_sign: names.append("crl_sign")
        if ku.encipher_only: names.append("encipher_only")
        if ku.decipher_only: names.append("decipher_only")
        return names
    
    def get_eku_names(eku):
        return [oid_name(o.dotted_string) for o in eku]
    
    extensions = []
    try:
        for ext in cert.extensions:
            ext_info = {}
            ext_info['id'] = ext.oid.dotted_string
            ext_info['name'] = oid_name(ext_info['id'])
            ext_info['critical'] = ext.critical
            
            val = ext.value
            if isinstance(val, crypto_x509.BasicConstraints):
                ext_info['ca'] = val.ca
                if val.path_length is not None:
                    ext_info['path_len'] = val.path_length
            elif isinstance(val, crypto_x509.KeyUsage):
                ext_info['value'] = get_ku_names(val)
            elif isinstance(val, crypto_x509.ExtendedKeyUsage):
                ext_info['value'] = get_eku_names(val)
            elif isinstance(val, crypto_x509.SubjectAlternativeName):
                sans = []
                for name in val:
                    if isinstance(name, crypto_x509.DNSName):
                        sans.append(f"DNS:{name.value}")
                    elif isinstance(name, crypto_x509.RFC822Name):
                        sans.append(f"email:{name.value}")
                    elif isinstance(name, crypto_x509.DirectoryName):
                        sans.append(f"dirName:{name.value.rfc4514_string()}")
                    elif isinstance(name, crypto_x509.IPAddress):
                        sans.append(f"IP:{name.value}")
                    else:
                        sans.append(str(name))
                ext_info['value'] = sans
            elif isinstance(val, crypto_x509.SubjectKeyIdentifier):
                ext_info['value'] = val.digest.hex()
            elif isinstance(val, crypto_x509.AuthorityKeyIdentifier):
                aki = {}
                if val.key_identifier:
                    aki['key_id'] = val.key_identifier.hex()
                if val.authority_cert_issuer:
                    aki['issuer'] = [str(x) for x in val.authority_cert_issuer]
                if val.authority_cert_serial_number:
                    aki['serial'] = val.authority_cert_serial_number
                ext_info['value'] = aki
            elif isinstance(val, crypto_x509.CRLDistributionPoints):
                crl_list = []
                for dp in val:
                    dp_info = {}
                    if dp.full_name:
                        dp_info['urls'] = [str(u.value) for u in dp.full_name]
                    crl_list.append(dp_info)
                ext_info['value'] = crl_list
            elif isinstance(val, crypto_x509.CertificatePolicies):
                policies = []
                for pi in val:
                    pol = {'oid': pi.policy_identifier.dotted_string}
                    if pi.policy_qualifiers:
                        pol['qualifiers'] = [str(pq) for pq in pi.policy_qualifiers]
                    policies.append(pol)
                ext_info['value'] = policies
            elif isinstance(val, crypto_x509.AuthorityInformationAccess):
                aia = []
                for desc in val:
                    aia.append(f"{oid_name(desc.access_method.dotted_string)}: {desc.access_location.value}")
                ext_info['value'] = aia
            elif isinstance(val, crypto_x509.PrecertificateSignedCertificateTimestamps):
                ext_info['value'] = [f"SCT({len(sct)} bytes)" for sct in val]
            elif isinstance(val, crypto_x509.PrecertPoison):
                ext_info['value'] = "precert_poison"
            elif isinstance(val, crypto_x509.InhibitAnyPolicy):
                ext_info['value'] = f"skip_certs={val.skip_certs}"
            elif isinstance(val, crypto_x509.PolicyConstraints):
                pc = []
                if val.require_explicit_policy is not None:
                    pc.append(f"require_explicit_policy={val.require_explicit_policy}")
                if val.inhibit_policy_mapping is not None:
                    pc.append(f"inhibit_policy_mapping={val.inhibit_policy_mapping}")
                ext_info['value'] = pc
            elif isinstance(val, crypto_x509.NameConstraints):
                nc = []
                if val.permitted_subtrees:
                    nc.append(f"permitted={len(val.permitted_subtrees)}")
                if val.excluded_subtrees:
                    nc.append(f"excluded={len(val.excluded_subtrees)}")
                ext_info['value'] = nc
            else:
                ext_info['value'] = f"({type(val).__name__})"
            
            extensions.append(ext_info)
    except Exception as e:
        extensions.append({'id': 'error', 'name': 'extensions_error', 'critical': False, 'value': str(e)})
    
    info['extensions'] = extensions
    return info

def parse_pkcs7_with_asn1crypto(pkcs7_data, label):
    """使用 asn1crypto 解析 PKCS#7 签名数据"""
    results = []
    signer_infos = []
    digest_algos = []
    content_type = "unknown"
    
    try:
        ci = cms.ContentInfo.load(pkcs7_data)
        content_type = ci['content_type'].native
        
        if content_type != 'signed_data':
            # 尝试从 cryptography 直接提取证书
            try:
                certs = pkcs7.load_der_pkcs7_certificates(pkcs7_data)
                for j, cert in enumerate(certs):
                    cert_der = cert.public_bytes(Encoding.DER)
                    info = extract_cert_info(cert_der, j, label)
                    results.append(info)
                content_type = "signed_data (via cryptography)"
            except:
                pass
            return results, digest_algos, signer_infos, content_type
        
        sd = ci['content']
        for da in sd['digest_algorithms']:
            digest_algos.append(da['algorithm'].native)
        
        if sd['certificates']:
            for j, cert_choice in enumerate(sd['certificates']):
                cert = cert_choice.chosen
                cert_der = cert.dump()
                info = extract_cert_info(cert_der, j, label)
                results.append(info)
        
        if sd['signer_infos']:
            for si in sd['signer_infos']:
                si_info = {}
                si_info['version'] = si['version'].native
                if si['sid'].name == 'issuer_and_serial_number':
                    isn = si['sid'].chosen
                    si_info['issuer'] = format_rdn(isn['issuer'])
                    si_info['serial'] = isn['serial_number'].native
                si_info['digest_algo'] = si['digest_algorithm']['algorithm'].native
                si_info['sig_algo'] = si['signature_algorithm']['algorithm'].native
                if si['signed_attrs']:
                    attrs = []
                    for attr in si['signed_attrs']:
                        attrs.append(attr['type'].native)
                    si_info['signed_attrs'] = attrs
                if si['unsigned_attrs']:
                    uattrs = []
                    for attr in si['unsigned_attrs']:
                        uattrs.append(attr['type'].native)
                    si_info['unsigned_attrs'] = uattrs
                signer_infos.append(si_info)
        
        return results, digest_algos, signer_infos, content_type
    except Exception as e:
        # 最后一次尝试: cryptography 直接加载
        try:
            certs = pkcs7.load_der_pkcs7_certificates(pkcs7_data)
            for j, cert in enumerate(certs):
                cert_der = cert.public_bytes(Encoding.DER)
                info = extract_cert_info(cert_der, j, label)
                results.append(info)
            return results, [], [], "signed_data (via cryptography fallback)"
        except:
            pass
        print(f"  {label}: Parse error: {e}")
        return [], [], [], "error"

# ============================================================
# 3. 解析所有 PKCS#7 块
# ============================================================
# Thawte PKCS#7 #1
certs, dgst, sigs, ct = parse_pkcs7_with_asn1crypto(thawte_pkcs7_1, "Thawte PKCS#7 #1 (gap 0xD3F8)")
for c in certs:
    all_certs.append(c)
all_blocks.append({
    'name': 'Thawte PKCS#7 #1 (gap 0xD3F8)',
    'size': len(thawte_pkcs7_1),
    'content_type': ct,
    'digest_algos': dgst,
    'signer_infos': sigs,
    'cert_count': len(certs)
})

# Thawte PKCS#7 #2
certs, dgst, sigs, ct = parse_pkcs7_with_asn1crypto(thawte_pkcs7_2, "Thawte PKCS#7 #2 (after PE2 0x16BD8)")
for c in certs:
    all_certs.append(c)
all_blocks.append({
    'name': 'Thawte PKCS#7 #2 (after PE2 0x16BD8)',
    'size': len(thawte_pkcs7_2),
    'content_type': ct,
    'digest_algos': dgst,
    'signer_infos': sigs,
    'cert_count': len(certs)
})

# Pikachu PKCS#7 #1 (inner signedData at 0xE49A, wrapped in NestedSignature at 0xE486)
certs, dgst, sigs, ct = parse_pkcs7_with_asn1crypto(pikachu_signed_1, "Pikachu PKCS#7 #1 (gap 0xE49A, inner signedData)")
for c in certs:
    all_certs.append(c)
all_blocks.append({
    'name': 'Pikachu PKCS#7 #1 (gap 0xE486→0xE49A, NestedSignature→signedData)',
    'size': len(pikachu_signed_1),
    'content_type': ct,
    'digest_algos': dgst,
    'signer_infos': sigs,
    'cert_count': len(certs)
})

# Pikachu PKCS#7 #2 (inner signedData at 0x17C7A, wrapped in NestedSignature at 0x17C66)
certs, dgst, sigs, ct = parse_pkcs7_with_asn1crypto(pikachu_signed_2, "Pikachu PKCS#7 #2 (after PE2 0x17C7A, inner signedData)")
for c in certs:
    all_certs.append(c)
all_blocks.append({
    'name': 'Pikachu PKCS#7 #2 (after PE2 0x17C66→0x17C7A, NestedSignature→signedData)',
    'size': len(pikachu_signed_2),
    'content_type': ct,
    'digest_algos': dgst,
    'signer_infos': sigs,
    'cert_count': len(certs)
})

print(f"\nTotal certificates parsed: {len(all_certs)}")

# 去重
seen = set()
unique_certs = []
for c in all_certs:
    if c['sha256'] not in seen:
        seen.add(c['sha256'])
        unique_certs.append(c)

print(f"Unique certificates: {len(unique_certs)}")

# 分类
thawte_certs = [c for c in unique_certs if 'thawte' in c['subject'].lower() or '韦' in c['subject']]
pikachu_certs = [c for c in unique_certs if 'Pikachu' in c['subject']]

print(f"Thawte certificates: {len(thawte_certs)}")
print(f"Pikachu certificates: {len(pikachu_certs)}")

for c in unique_certs:
    print(f"  [{c['source'][:20]}...] {c['subject'][:80]} | 自签名={c['self_signed']}")

# ============================================================
# 4. 生成报告
# ============================================================
def write_report():
    lines = []
    def w(line=""):
        lines.append(line)
    
    w("=" * 80)
    w("Pikachu 自建证书链完整分析报告")
    w("=" * 80)
    w(f"生成时间: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
    w(f"分析目标: enhr_embedded/enhr_outer.exe")
    w(f"唯一证书总数: {len(unique_certs)}")
    w()
    
    # ============================================================
    w("=" * 80)
    w("一、证书数据位置概览")
    w("=" * 80)
    w()
    w("enhr_outer.exe 包含两个证书数据存储区域:")
    w()
    w("  区域A: 0xD3F0 - 0xF1D0 (PE1 和 PE2 之间的 gap, 7648 bytes)")
    w("    0xD3F0: 8字节自定义头部 (4字节size=0x1DD8 + 4字节=0x00000202)")
    w("    0xD3F8: Thawte PKCS#7 SignedData (7626 bytes, 含3个Thawte证书)")
    w("    0xE486: Pikachu PKCS#7 NestedSignature (外层包装, 3388 bytes)")
    w("      0xE49A: 内层 signedData (3368 bytes, 含1个Pikachu证书)")
    w()
    w("  区域B: 0x16BD0 - 0x1BC00 (PE2 之后, 20272 bytes)")
    w("    0x16BD0: 8字节自定义头部 (4字节size=0x1DC0 + 4字节=0x00000202)")
    w("    0x16BD8: Thawte PKCS#7 SignedData (7601 bytes, 含3个Thawte证书)")
    w("    0x17C66: Pikachu PKCS#7 NestedSignature (外层包装, 3363 bytes)")
    w("      0x17C7A: 内层 signedData (3343 bytes, 含1个Pikachu证书)")
    w("    0x18989+: 剩余数据 (12919 bytes, 非证书数据/加密配置)")
    w()
    w("  注意: 两个区域包含相同的证书数据 (冗余备份)")
    w("  Pikachu PKCS#7 使用 Microsoft szOID_NESTED_SIGNATURE 包装")
    w("  (OID: 1.3.6.1.4.1.311.3.3.1), 常用于 Windows 内核驱动签名")
    w()
    
    # ============================================================
    w("=" * 80)
    w("二、PKCS#7 签名数据块概览")
    w("=" * 80)
    w()
    for i, block in enumerate(all_blocks):
        w(f"块 #{i+1}: {block['name']}")
        w(f"  大小: {block['size']} bytes")
        w(f"  内容类型: {block['content_type']}")
        if block['digest_algos']:
            w(f"  摘要算法: {', '.join(block['digest_algos'])}")
        w(f"  证书数量: {block['cert_count']}")
        if block['signer_infos']:
            for si in block['signer_infos']:
                w(f"  签名者: {si.get('issuer', 'N/A')}")
                w(f"  签名者序列号: {si.get('serial', 'N/A')}")
                w(f"  摘要算法: {si.get('digest_algo', 'N/A')}")
                w(f"  签名算法: {si.get('sig_algo', 'N/A')}")
                if si.get('signed_attrs'):
                    w(f"  签名属性: {', '.join(si['signed_attrs'])}")
                if si.get('unsigned_attrs'):
                    w(f"  未签名属性: {', '.join(si['unsigned_attrs'])}")
        w()
    
    # ============================================================
    w("=" * 80)
    w("三、完整证书解析 (每个证书的详细信息)")
    w("=" * 80)
    w()
    
    for i, cert in enumerate(unique_certs):
        w(f"{'='*60}")
        w(f"证书 #{i+1}: {cert['subject']}")
        w(f"{'='*60}")
        w(f"  来源: {cert['source']}")
        w(f"  主题 (Subject):")
        for line in cert['subject'].split(','):
            w(f"    {line.strip()}")
        w(f"  颁发者 (Issuer):")
        for line in cert['issuer'].split(','):
            w(f"    {line.strip()}")
        w(f"  序列号 (Serial):")
        w(f"    十进制: {cert['serial']}")
        w(f"    十六进制: 0x{cert['serial']:X}")
        w(f"  有效期:")
        if isinstance(cert['not_before'], datetime):
            w(f"    Not Before: {cert['not_before'].strftime('%Y-%m-%d %H:%M:%S UTC')}")
        else:
            w(f"    Not Before: {cert['not_before']}")
        if isinstance(cert['not_after'], datetime):
            w(f"    Not After:  {cert['not_after'].strftime('%Y-%m-%d %H:%M:%S UTC')}")
        else:
            w(f"    Not After:  {cert['not_after']}")
        
        if isinstance(cert['not_before'], datetime) and isinstance(cert['not_after'], datetime):
            days = (cert['not_after'] - cert['not_before']).days
            w(f"    有效天数: {days} 天 ({days/365.25:.1f} 年)")
            # 是否已过期
            now = datetime.now(cert['not_after'].tzinfo)
            if cert['not_after'] < now:
                w(f"    状态: ★ 已过期 (过期于 {cert['not_after'].strftime('%Y-%m-%d')})")
            elif cert['not_before'] > now:
                w(f"    状态: ★ 尚未生效")
            else:
                w(f"    状态: 有效期内")
        
        w(f"  签名算法: {cert['sig_algo']}")
        w(f"  公钥算法: {cert['pubkey_algo']}")
        w(f"  公钥大小: {cert['pubkey_size']} bits")
        w(f"  自签名: {'是 (ROOT CA)' if cert['self_signed'] else '否'}")
        w(f"  SHA1 指纹:")
        w(f"    {cert['sha1']}")
        w(f"  SHA256 指纹:")
        w(f"    {cert['sha256']}")
        
        if cert['extensions']:
            w(f"  X.509 v3 扩展字段 ({len(cert['extensions'])} 个):")
            for ext in cert['extensions']:
                critical = " ★关键" if ext['critical'] else ""
                w(f"    [{ext['name']}] ({ext['id']}){critical}:")
                if 'ca' in ext:
                    w(f"      CA: {ext['ca']}")
                    if 'path_len' in ext:
                        w(f"      Path Length Constraint: {ext['path_len']}")
                if 'value' in ext:
                    if isinstance(ext['value'], dict):
                        for k, v in ext['value'].items():
                            w(f"      {k}: {v}")
                    elif isinstance(ext['value'], list):
                        for item in ext['value']:
                            w(f"      - {item}")
                    else:
                        w(f"      {ext['value']}")
        w()
    
    # ============================================================
    w("=" * 80)
    w("四、证书链结构图")
    w("=" * 80)
    w()
    
    w("--- 4.1 Thawte 代码签名证书链 (3个证书) ---")
    w()
    w("  ┌─ cert #A1: CN=thawte Primary Root CA")
    w("  │   角色: 中间根CA (非自签名，由外部 Thawte Premium Server CA 签发)")
    w("  │   有效期: 2006-11-17 ~ 2020-12-30 (14.1年) ★ 已过期")
    w("  │   公钥: RSA 2048 bits")
    w("  │   KeyUsage: key_cert_sign, crl_sign")
    w("  │   BasicConstraints: CA=True, pathLen=None")
    w("  │")
    w("  └──▶ cert #A2: CN=thawte SHA256 Code Signing CA")
    w("        角色: 签发CA (中间CA)")
    w("        有效期: 2013-12-10 ~ 2023-12-09 (10.0年) ★ 已过期")
    w("        公钥: RSA 2048 bits")
    w("        KeyUsage: key_cert_sign, crl_sign")
    w("        ExtKeyUsage: clientAuth, codeSigning")
    w("        BasicConstraints: CA=True, pathLen=0")
    w("        SAN: SymantecPKI-1-568")
    w("        │")
    w("        └──▶ cert #A3: CN=善君 韦 (代码签名证书)")
    w("              角色: 终端实体 (叶子证书)")
    w("              有效期: 2014-12-29 ~ 2015-12-29 (1.0年) ★ 已过期")
    w("              公钥: RSA 2048 bits")
    w("              KeyUsage: digital_signature")
    w("              ExtKeyUsage: codeSigning")
    w("              BasicConstraints: CA=False")
    w()
    w("  签名者信息:")
    w("    签名证书: CN=善君 韦")
    w("    签名序列号: 122008879129994679422631457085243744467")
    w("    摘要算法: sha256")
    w("    签名算法: rsassa_pkcs1v15")
    w("    签名属性: spc_sp_opus_info, contentType, spc_statement_type, messageDigest")
    w()
    
    w("--- 4.2 Pikachu 自建证书链 ---")
    w()
    
    root_cas = [c for c in pikachu_certs if c['self_signed']]
    sub_cas = [c for c in pikachu_certs if not c['self_signed'] and any(
        ext.get('ca') for ext in c['extensions'] if 'ca' in ext
    )]
    leaf_certs = [c for c in pikachu_certs if not c['self_signed'] and not any(
        ext.get('ca') for ext in c['extensions'] if 'ca' in ext
    )]
    
    w(f"Pikachu 自建 PKI 体系 (本文件中包含 {len(pikachu_certs)} 个证书):")
    w(f"  Root CA (自签名根): {len(root_cas)} 个")
    w(f"  Sub CA (中间CA):    {len(sub_cas)} 个")
    w(f"  Leaf (终端实体):    {len(leaf_certs)} 个")
    w()
    w("  ★ 注意: Pikachu Root CA 证书 (Pikachu Test CA RSA) 未包含在此文件中!")
    w("     仅包含由 Root CA 签发的 Time Sub CA 证书")
    w("     Root CA 信息只能从 Sub CA 证书的 Issuer 字段和签名者信息中推断")
    w()
    
    w("  证书链:")
    w()
    w("  ┌─ [外部] Pikachu Test CA RSA (Root CA, 未嵌入)")
    w("  │   CN=Pikachu Test CA RSA")
    w("  │   OU=Pikachu Certification Authority")
    w("  │   O=Pikachu Trust Network CA")
    w("  │   C=CN")
    w("  │   email=testca@certs.us.kg")
    w("  │   描述: 皮卡丘公共服务测试根证书 RSA / Pikachu Public Test Root RSA")
    w("  │")
    w("  └──▶ cert #P1: Pikachu Time Sub CA (本文件中唯一Pikachu证书)")
    w("        角色: 时间戳签署中间CA")
    w("        有效期: 2014-12-24 ~ 2034-12-22 (20年)")
    w("        公钥: RSA 2048 bits")
    w("        KeyUsage: digital_signature, key_cert_sign, crl_sign")
    w("        ExtKeyUsage: timeStamping (时间戳签名)")
    w("        BasicConstraints: CA=True, pathLen=1")
    w("        email=timeca@certs.us.kg")
    w("        描述: 皮卡丘时间戳签署中间CA子证书 / Pikachu Time Signning Sub CA")
    w()
    
    w("  签名者信息:")
    w("    签名证书: Pikachu Test CA RSA (Root CA)")
    w("    签名序列号: 1435378853582644434 (0x13EB7D765DE6A4D2)")
    w("    摘要算法: Pikachu #1=sha1, Pikachu #2=sha256")
    w("    签名算法: rsassa_pkcs1v15")
    w()
    
    # ============================================================
    w("=" * 80)
    w("五、Pikachu CA 体系分析")
    w("=" * 80)
    w()
    w("Pikachu 自建 PKI (公钥基础设施) 体系分析:")
    w()
    w("  组织: Pikachu Trust Network CA")
    w("  部门: Pikachu Certification Authority")
    w("  国家: CN (中国)")
    w("  域名: certs.us.kg (免费域名服务)")
    w()
    w("  已知证书角色:")
    w("    1. Pikachu Test CA RSA (Root CA)")
    w("       - 根证书, 自签名")
    w("       - 邮箱: testca@certs.us.kg")
    w("       - 描述: 皮卡丘公共服务测试根证书 RSA")
    w("       - 猜测有效期: 20年 (2014~2034)")
    w()
    w("    2. Pikachu Time Sub CA (时间戳签署CA) ★ 本文件中包含")
    w("       - 中间CA, 由 Root CA 签发")
    w("       - 邮箱: timeca@certs.us.kg")
    w("       - 描述: 皮卡丘时间戳签署中间CA子证书")
    w("       - 用途: 时间戳签名 (timeStamping)")
    w("       - 有效期: 2014-12-24 ~ 2034-12-22 (20年)")
    w("       - 可签发下级证书 (pathLen=1)")
    w()
    w("  推测: Pikachu 完整的 PKI 体系可能包含以下类型的子 CA:")
    w("    (基于常见 PKI 最佳实践和恶意软件模式)")
    w("    1. Root CA - 根证书 (自签名)")
    w("    2. Time Sub CA - 时间戳签署CA ★ 已确认")
    w("    3. Code Signing Sub CA - 代码签名CA")
    w("    4. TLS Server Sub CA - 服务器TLS证书CA")
    w("    5. TLS Client Sub CA - 客户端TLS证书CA")
    w("    6. Email Sub CA - 邮件签名/加密CA")
    w("    7. OCSP Responder Sub CA - OCSP响应CA")
    w("    8. Component Sub CA - 组件签名CA")
    w()
    w("  注意: 本文件中仅嵌入了 Time Sub CA 证书。")
    w("  其他子 CA 证书可能存储在:")
    w("    - 其他 PE 文件/DLL 中")
    w("    - 服务器端 (运行时下载)")
    w("    - 加密的配置数据中 (0x18989 之后的 12919 bytes)")
    w()
    
    # ============================================================
    w("=" * 80)
    w("六、开发者个人信息")
    w("=" * 80)
    w()
    w("  从 Thawte 代码签名证书中提取的开发者信息:")
    w()
    w("    姓名:   善君 韦 (Wei Shanjun)")
    w("    身份:   个人开发者 (Individual Developer)")
    w("    组织:   无组织隶属 (No Organization Affiliation)")
    w("    城市:   崇左市 (Chongzuo)")
    w("    省份:   广西壮族自治区 (Guangxi)")
    w("    国家:   中国 (CN)")
    w("    证书来源: Thawte 代码签名证书")
    w("    证书序列号: 122008879129994679422631457085243744467")
    w("    证书有效期: 2014-12-29 ~ 2015-12-29")
    w()
    w("  从 Pikachu 自建证书中提取的信息:")
    w()
    w("    组织名:   Pikachu Trust Network CA")
    w("    部门:     Pikachu Certification Authority")
    w("    域名:     certs.us.kg (免费域名服务)")
    w("    Root CA 邮箱: testca@certs.us.kg")
    w("    Time CA 邮箱: timeca@certs.us.kg")
    w("    国家:     CN (中国)")
    w()
    w("  分析:")
    w("    - 代码签名证书中的个人信息 (韦善君, 广西崇左) 与 Pikachu CA 可能有关联")
    w("    - 两者都来自中国, 时间上高度吻合 (2014年底)")
    w("    - certs.us.kg 是免费域名, 无法追踪真实所有者")
    w("    - Pikachu 的描述字段使用中文和英文双语")
    w()
    
    # ============================================================
    w("=" * 80)
    w("七、安全分析总结")
    w("=" * 80)
    w()
    w("1. 代码签名:")
    w("   - 使用 Thawte (后并入 Symantec/DigiCert) 颁发的合法代码签名证书")
    w("   - 证书持有人: 善君 韦 (Wei Shanjun), 个人开发者")
    w("   - 证书有效期: 2014-12-29 ~ 2015-12-29 (仅1年)")
    w("   - 证书已于 2015年12月29日过期, 签名不再受 Windows 信任")
    w("   - 签名算法: SHA256 + RSA 2048")
    w("   - 过期时间戳表明: 开发者可能仅计划短期使用此签名")
    w()
    w("2. Pikachu 自建 PKI 体系:")
    w("   - 完全自建的证书体系, 不依赖任何公共信任根")
    w("   - 根证书使用 RSA 2048 位密钥")
    w("   - 使用标准 X.509 v3 证书格式和 PKCS#7 签名")
    w("   - 采用 Microsoft szOID_NESTED_SIGNATURE 包装 (内核驱动签名格式)")
    w("   - 时间戳 CA 可用于伪造文件时间戳, 绕过基于时间的检测")
    w()
    w("3. 数据嵌入方式:")
    w("   - 证书数据嵌入在 PE 覆盖层 (overlay) 中")
    w("   - 格式: 8字节自定义头部 + 标准 PKCS#7 DER 数据")
    w("   - 双重冗余存储 (两个区域各一份完整副本)")
    w("   - 头部 4字节为数据大小, 后4字节固定为 0x00000202")
    w()
    w("4. 时间线分析:")
    w("   - Pikachu Root CA 创建: 约 2014-12-24")
    w("   - Pikachu Time Sub CA 创建: 2014-12-24")
    w("   - Thawte 代码签名证书签发: 2014-12-29")
    w("   - 证书有效期模式: 20年 (Pikachu) vs 1年 (Thawte)")
    w("   - 样本可能编译于 2014年底 ~ 2015年期间")
    w()
    w("5. 威胁评估:")
    w("   - 自建 CA 体系 + 时间戳 CA 是恶意软件的常见特征")
    w("   - 结合其他分析结果 (反调试、键盘记录、DLL注入等), 综合判断为恶意软件")
    w("   - 开发者曾获取合法代码签名证书以绕过安全检测")
    w("   - 自建 PKI 可能用于:")
    w("     a) 内部组件间加密通信")
    w("     b) 伪造文件时间戳 (利用 Time Sub CA)")
    w("     c) 签名恶意驱动/内核模块")
    w("     d) 建立信任链以绕过安全检查")
    w()
    
    # ============================================================
    w("=" * 80)
    w("八、证书指纹汇总")
    w("=" * 80)
    w()
    for i, c in enumerate(unique_certs):
        w(f"证书 #{i+1}: {c['subject']}")
        w(f"  SHA1:   {c['sha1']}")
        w(f"  SHA256: {c['sha256']}")
        w()
    
    w("=" * 80)
    w("报告结束")
    w("=" * 80)
    
    return "\n".join(lines)

# 生成报告
report = write_report()

# 保存
os.makedirs(os.path.dirname(OUTPUT), exist_ok=True)
with open(OUTPUT, "w", encoding="utf-8") as f:
    f.write(report)

print(f"\n报告已保存到: {OUTPUT}")
print(f"报告长度: {len(report)} 字符")
print(f"报告行数: {len(report.split(chr(10)))} 行")

# 打印报告前 100 行
print("\n" + "="*80)
print("报告预览")
print("="*80)
for line in report.split("\n")[:100]:
    print(line)