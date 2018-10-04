""" USAGE

plaintext = 'This is unencrypted sample text'
ciphertext = rot13(plaintext)

or

ciphertext = 'Guvf vf harapelcgrq fnzcyr grkg'
plaintext = rot13(ciphertext)
"""

def rot13(string):
    result = ''
    for ch in string:
            ascii_value = ord(ch)
            if ch == ' ':
                    result += ' '
            elif ascii_value >= 65 and ascii_value <= 90:
                    if ascii_value + 13 > 90:
                            result += chr(ascii_value - 13)
                    else:
                            result += chr(ascii_value + 13)	
            elif ascii_value >= 97 and ascii_value <= 122:	
                    if ascii_value + 13 > 122:
                                    result += chr(ascii_value - 13)	
                    else:
                            result += chr(ascii_value + 13)		
    return result
