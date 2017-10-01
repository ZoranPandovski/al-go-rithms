def encrypt(plaintext):
	alphabet=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
	substitutionarray=['1','4','7','5','F','G','A','B','2','S','N','3','C','T','6','M','6','D','X','R','L','U','K','8','O','9']
	ciphertext=""
	for i in plaintext:
		ciphertext=ciphertext+substitutionarray[alphabet.index(i)]
	return ciphertext


def decrypt(ciphertext):
	alphabet=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
	substitutionarray=['1','4','7','5','F','G','A','B','2','S','N','3','C','T','6','M','6','D','X','R','L','U','K','8','O','9']
	reverseplaintext=""
	for i in ciphertext:
		reverseplaintext=reverseplaintext+alphabet[substitutionarray.index(i)]
	return reverseplaintext


def test():
    cipher = encrypt("youcantbreakme")
    plain_text = decrypt(cipher)
    assert plain_text == "youcantbreakme"


if __name__ == "__main__":
    test()



