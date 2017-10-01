alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
            'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
            'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']


def encrypt(plaintext):
    # samelength
    key = "welltrytodoso"
    string = ""
    k = 0
    for i in plaintext:
        string = string + alphabet[alphabet.index(i) + alphabet.index(key[k])]
        k = k + 1
    return string


def decrypt(ciphertext):
    key = "welltrytodoso"
    string = ""
    k = 0
    for i in ciphertext:
        string = string + alphabet[alphabet.index(i) - alphabet.index(key[k])]
        k = k + 1
    return string


def test():
    cipher = encrypt("youcantbreakme")
    plain_text = decrypt(cipher)
    assert plain_text == "youcantbreakme"


if __name__ == "__main__":
    test()
