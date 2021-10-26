from __future__ import print_function
import numpy as np

# The key is based on 3 x 3, but can change it
key = np.array([[1,2,3],
				[4,5,6],
				[7,8,9],])

def toNumber(ar):
	for i, val in enumerate(ar):
		ar[i] = ord(val) - 97
	return ar


def encrypt(word, key):
	word = word.lower()
	encrypted = ""
	encodedChunk = ""
	chunk = []	#the chunks of 3
	midmat = [] # intermediate matrix
	for i in range(0,len(word)+1,3):
		chunk = toNumber(list(word[i:i+3]))
		if (len(chunk) == 0):
			break
		else:
			chunk = np.asarray(chunk)

		encodedChunk = ((np.matmul(key, chunk)%26)+97).tostring().decode("ascii")
		encrypted += encodedChunk

	return encrypted


# User input
while True:
	toEncrypt = input("Please enter a word/phrase to encrypt with a length divisible by 3:\n")
	if (len(toEncrypt.strip()) % 3 != 0):
		print("\nEnter a valid length!")
		toEncrypt = input("Please enter a word/phrase to encrypt:\n")
	elif not toEncrypt.strip().isalpha():
		print("\nEnter only alphabetical!")
		toEncrypt = input("Please enter a word/phrase to encrypt:\n")
	else:
		break

print(encrypt(toEncrypt, key))