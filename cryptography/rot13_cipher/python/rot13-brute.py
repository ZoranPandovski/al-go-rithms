# Caesar Cipher
# Source-code from https://inventwithpython.com/chapter14.html

""" 
Usage:
         python3 rot13-brute.py
 
enter option "e" for encrypt, "d" for decrypt, and "b" for brute/generate
"""

MAX_KEY_SIZE = 26

def getMode():
	while True:
		print ("Do you wish to encrypt[e] or decrypt[d] or brute[b] force a message?")
		mode = input().lower()
		if mode in 'encrypt e decrypt d brute b'.split():
			return mode[0]
		else:
			print ('Enter either "encrypt" or "e" or "decrypt" or "d" or "brute" or "b".')

def getMessage():
	print ('Enter your message:')
	return input()

def getKey():
	key = 0
	while True:
		print ('Enter the key number(1-%s)' % (MAX_KEY_SIZE))
		key = int(input())
		if(key >= 1 and key <= MAX_KEY_SIZE):
			return key

def getTranslateMessage(mode, message, key):
	if mode[0] == 'd':
		key = -key
		translated = ''

	for symbol in message:
		if symbol.isalpha():
			num = ord(symbol)
			num += key

			if symbol.isupper():
				if num > ord('Z'):
					num -= 26
				elif num < ord('A'):
					num += 26
			elif symbol.islower():
				if num > ord('z'):
					num -= 26
				elif num < ord('a'):
					num += 26

			translated += chr(num)
		else:
			translated += symbol
	return translated

mode = getMode()
message = getMessage()
if mode[0] != 'b':
	key = getKey()

print('Your translated text is:')
if mode[0] != 'b':
	print(getTranslateMessage(mode, message, key))
else:
	for key in range(1, MAX_KEY_SIZE + 1):
		print(key,getTranslateMessage('decrypt',message,key))
