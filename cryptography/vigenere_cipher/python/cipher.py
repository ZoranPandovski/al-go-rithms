def char_position(letter):
    return ord(letter) - 97

def pos_to_char(pos):
    return chr(pos + 97)

alphabet=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']

def encrypt(plaintext):
	key="secret"
	string=""
	i=0
	while i<len(plaintext):
		string=string+str(alphabet[char_position(plaintext[i])+char_position(key[i%len(key)])])
		i=i+1
	return string
def decrypt(ciphertext):
	key="secret"
	string=""
	i=0
	while i<len(ciphertext):


		string=string+str(alphabet[alphabet.index(ciphertext[i])-char_position(key[i%len(key)])])
		i=i+1
	return string

print encrypt("youcantbreakme")
print decrypt(encrypt("youcantbreakme"))

