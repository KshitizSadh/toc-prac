def rail_fence_encrypt(text, rails):
    fence = [[] for _ in range(rails)]
    rail, direction = 0, 1
    
    for char in text:
        fence[rail].append(char)
        rail += direction
        if rail == 0 or rail == rails - 1:
            direction *= -1
    
    return ''.join([''.join(row) for row in fence])

def rail_fence_decrypt(cipher, rails):
    fence = [[None] * len(cipher) for _ in range(rails)]
    rail, direction = 0, 1
    
    for i in range(len(cipher)):
        fence[rail][i] = '*'
        rail += direction
        if rail == 0 or rail == rails - 1:
            direction *= -1
    
    index = 0
    for r in range(rails):
        for c in range(len(cipher)):
            if fence[r][c] == '*':
                fence[r][c] = cipher[index]
                index += 1
    
    result, rail, direction = [], 0, 1
    for i in range(len(cipher)):
        result.append(fence[rail][i])
        rail += direction
        if rail == 0 or rail == rails - 1:
            direction *= -1
    
    return ''.join(result)

# Usage
text = input("Enter text: ")
rails = int(input("Enter rails: "))
encrypted = rail_fence_encrypt(text, rails)
decrypted = rail_fence_decrypt(encrypted, rails)
print(f"Encrypted: {encrypted}\nDecrypted: {decrypted}")
