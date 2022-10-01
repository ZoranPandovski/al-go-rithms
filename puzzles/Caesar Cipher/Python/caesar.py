import string

class CaesarCipher:
  def encrypt(self, plaintext, key):
    ciphertext = ""
    for letter in plaintext:
      if letter in string.ascii_lowercase:
        ciphertext += chr(((ord(letter) - ord('a') + key) % len(string.ascii_lowercase)) + ord('a'))
      elif letter in string.ascii_uppercase:
        ciphertext += chr(((ord(letter) - ord('A') + key) % len(string.ascii_uppercase)) + ord('A'))
      else:
        ciphertext += letter
    return ciphertext

  def decrypt(self, ciphertext, key):
    plaintext = ""
    for letter in ciphertext:
      if letter in string.ascii_lowercase:
        plaintext += chr(((ord(letter) - ord('a') - key) % len(string.ascii_lowercase)) + ord('a'))
      elif letter in string.ascii_uppercase:
        plaintext += chr(((ord(letter) - ord('A') - key) % len(string.ascii_uppercase)) + ord('A'))
      else:
        plaintext += letter
    return plaintext


if __name__ == "__main__":
  plaintext = "This is test number 1!"
  key = 42
  c = CaesarCipher()
  ciphertext = c.encrypt(plaintext, key)
  decrypted = c.decrypt(ciphertext, key)
  print("Generated Ciphertext: ", ciphertext)
  print("Decrypted Plaintext: ", decrypted)