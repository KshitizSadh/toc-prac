import hashlib
import requests

def check_breach(password):
    sha1 = hashlib.sha1(password.encode()).hexdigest().upper()
    prefix, suffix = sha1[:5], sha1[5:]
    
    response = requests.get(f"https://api.pwnedpasswords.com/range/{prefix}")
    hashes = (line.split(':') for line in response.text.splitlines())
    
    for h, count in hashes:
        if h == suffix:
            return True, int(count)
    return False, 0

# Usage
filename = input("Enter file (username,password format): ")
with open(filename) as f:
    for line in f:
        user, pwd = line.strip().split(',')
        breached, count = check_breach(pwd)
        status = f"LEAKED ({count}x)" if breached else "Safe"
        print(f"{user}: {status}")
