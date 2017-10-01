alphabet=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']


def encrypt(plaintext):
    key="secret"
    string=""
    i=0
    while i<len(plaintext):
        string=string+alphabet[alphabet.index(plaintext[i])+alphabet.index(key[i%len(key)])]
        i=i+1
    return string


def decrypt(ciphertext):
    key="secret"
    string=""
    i=0
    while i<len(ciphertext):
        string=string+alphabet[alphabet.index(ciphertext[i])-alphabet.index(key[i%len(key)])]
        i=i+1
    return string


def test():
    cipher = encrypt("youcantbreakme")
    plain_text = decrypt(cipher)
    assert plain_text == "youcantbreakme"


if __name__ == "__main__":
    test()

