from cryptography.hazmat.primitives import hashes, serialization
from cryptography.hazmat.primitives.asymmetric import rsa, padding
import base64

# Generate keys
private_key = rsa.generate_private_key(public_exponent=65537, key_size=2048)
public_key = private_key.public_key()

# Sign document
document = input("Enter document: ").encode()
signature = private_key.sign(
    document,
    padding.PSS(mgf=padding.MGF1(hashes.SHA256()), salt_length=padding.PSS.MAX_LENGTH),
    hashes.SHA256()
)

print(f"\nSignature: {base64.b64encode(signature).decode()[:50]}...")

# Verify signature
try:
    public_key.verify(signature, document, 
                     padding.PSS(mgf=padding.MGF1(hashes.SHA256()), 
                                salt_length=padding.PSS.MAX_LENGTH),
                     hashes.SHA256())
    print("✓ Signature VALID")
except:
    print("✗ Signature INVALID")
