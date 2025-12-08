def caesar_encrypt(text, shift):
    result = ""
    for char in text:
        if char.isalpha():
            base = 65 if char.isupper() else 97
            result += chr((ord(char) - base + shift) % 26 + base)
        else:
            result += char
    return result

def caesar_decrypt(text, shift):
    return caesar_encrypt(text, -shift)

# Usage
text = input("Enter text: ")
shift = int(input("Enter shift: "))
encrypted = caesar_encrypt(text, shift)
decrypted = caesar_decrypt(encrypted, shift)
print(f"Encrypted: {encrypted}\nDecrypted: {decrypted}")
