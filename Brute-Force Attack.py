import itertools
import string

def brute_force(target, charset=string.ascii_lowercase, max_len=4):
    attempts = 0
    for length in range(1, max_len + 1):
        for attempt in itertools.product(charset, repeat=length):
            attempts += 1
            guess = ''.join(attempt)
            if guess == target:
                return f"Found '{guess}' in {attempts} attempts"
    return f"Not found after {attempts} attempts"

# Usage
target = input("Enter target password: ")
print(brute_force(target))
