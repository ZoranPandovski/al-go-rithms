import random

def generate_key(length):
    """Generates a random binary key of a given length."""
    return ''.join([str(random.randint(0,1)) for i in range(length)])

def encrypt(plaintext, key):
    """Encrypts a plaintext message using a given key."""
    ciphertext = ''
    for i in range(len(plaintext)):
        # Perform bitwise XOR operation on each bit of the plaintext and key
        ciphertext += str(int(plaintext[i]) ^ int(key[i]))
    return ciphertext

def decrypt(ciphertext, key):
    """Decrypts a ciphertext message using a given key."""
    plaintext = ''
    for i in range(len(ciphertext)):
        # Perform bitwise XOR operation on each bit of the ciphertext and key
        plaintext += str(int(ciphertext[i]) ^ int(key[i]))
    return plaintext

# Example usage
plaintext = 'Hello World'
key = generate_key(len(plaintext))
ciphertext = encrypt(''.join(format(ord(c), '08b') for c in plaintext), key)
decrypted_text = decrypt(ciphertext, key)
print('Plaintext:', plaintext)
print('Key:', key)
print('Ciphertext:', ciphertext)
print('Decrypted Text:', ''.join(chr(int(decrypted_text[i:i+8], 2)) for i in range(0, len(decrypted_text), 8)))
