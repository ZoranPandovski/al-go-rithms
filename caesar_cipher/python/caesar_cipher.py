import string


def caesar_cipher(plaintext, shift):
    # get all alphabets
    alphabets = string.ascii_lowercase
    shift_alphabets = alphabets[shift:] + alphabets[:shift]
    table = string.maketrans(alphabets, shift_alphabets)
    cipher_text = plaintext.translate(table)
    return cipher_text


if __name__ == "__main__":
    print caesar_cipher('zdravo', 3)
