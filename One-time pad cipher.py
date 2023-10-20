import random

def generate_key(length):
    """Generates a random key of the specified length."""
    return bytes([random.randint(0, 255) for _ in range(length)])

def encrypt(plaintext, key):
    """Encrypts the plaintext using the provided key."""
    ciphertext = bytes([plaintext[i] ^ key[i] for i in range(len(plaintext))])
    return ciphertext

def decrypt(ciphertext, key):
    """Decrypts the ciphertext using the provided key."""
    plaintext = bytes([ciphertext[i] ^ key[i] for i in range(len(ciphertext))])
    return plaintext

# Example usage
plaintext = b"SECRET MESSAGE"
key = generate_key(len(plaintext))
ciphertext = encrypt(plaintext, key)
decrypted_text = decrypt(ciphertext, key)

print("Plaintext:", plaintext)
print("Key:", key)
print("Ciphertext:", ciphertext)
print("Decrypted text:", decrypted_text)
