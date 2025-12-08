import random

def generate_password(dict_file, words=4):
    with open(dict_file) as f:
        word_list = [line.strip() for line in f]
    
    selected = random.sample(word_list, words)
    password = '-'.join(selected) + str(random.randint(10, 99)) + random.choice('!@#$%')
    return password

# Usage
print(f"Password: {generate_password('words.txt', 3)}")
