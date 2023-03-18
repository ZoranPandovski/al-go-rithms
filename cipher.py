def caesar_cipher(plaintext, shift):
    ciphertext = ""
    for char in plaintext:
        if char.isalpha():
            if char.isupper():
                ciphertext += chr((ord(char) - 65 + shift) % 26 + 65)
            else:
                ciphertext += chr((ord(char) - 97 + shift) % 26 + 97)
        else:
            ciphertext += char
    return ciphertext
def vigenere_cipher(plaintext, key):
    ciphertext = ""
    key_index = 0
    for char in plaintext:
        if char.isalpha():
            if char.isupper():
                shift = ord(key[key_index % len(key)].upper()) - 65
                ciphertext += chr((ord(char) - 65 + shift) % 26 + 65)
            else:
                shift = ord(key[key_index % len(key)].lower()) - 97
                ciphertext += chr((ord(char) - 97 + shift) % 26 + 97)
            key_index += 1
        else:
            ciphertext += char
    return ciphertext
def create_playfair_matrix(keyword):
    alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"
    matrix = []
    for char in keyword.upper():
        if char not in matrix and char in alphabet:
            matrix.append(char)
    for char in alphabet:
        if char not in matrix:
            matrix.append(char)
    playfair_matrix = [matrix[i:i+5] for i in range(0, 25, 5)]
    return playfair_matrix

def playfair_cipher(plaintext, keyword):
    playfair_matrix = create_playfair_matrix(keyword)
    ciphertext = ""
    plaintext = plaintext.upper().replace("J", "I")
    plaintext = plaintext.replace(" ", "")
    plaintext = plaintext + "X" if len(plaintext) % 2 != 0 else plaintext
    for i in range(0, len(plaintext), 2):
        row1, col1 = divmod(playfair_matrix.index(playfair_matrix[int(playfair_matrix.index(plaintext[i])/5)]), 5)
        row2, col2 = divmod(playfair_matrix.index(playfair_matrix[int(playfair_matrix.index(plaintext[i+1])/5)]), 5)
        if row1 == row2:
            ciphertext += playfair_matrix[row1][(col1+1)%5]
            ciphertext += playfair_matrix[row2][(col2+1)%5]
        elif col1 == col2:
            ciphertext += playfair_matrix[(row1+1)%5][col1]
            ciphertext += playfair_matrix[(row2+1)%5][col2]
        else:
            ciphertext += playfair_matrix[row1][col2]
            ciphertext += playfair_matrix[row2][col1]
    return ciphertext
