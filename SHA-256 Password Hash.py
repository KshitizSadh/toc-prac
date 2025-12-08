import hashlib

def hash_password(password):
    return hashlib.sha256(password.encode()).hexdigest()

# Usage
password = input("Enter password: ")
print(f"SHA-256: {hash_password(password)}")
