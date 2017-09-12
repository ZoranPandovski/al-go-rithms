import string


def caesar_cipher(plaintext, shift):
    # get all alphabets
    alphabets = string.ascii_lowercase
    shift_alphabets = alphabets[shift:] + alphabets[:shift]
    table = string.maketrans(alphabets, shift_alphabets)
    cipher_text = plaintext.translate(table)
    return cipher_text


def test():
    cipher = 'Khoor'
    assert caesar_cipher('Hello', 3) == cipher


if __name__ == "__main__":
    test()