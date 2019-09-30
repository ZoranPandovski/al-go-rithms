#!/usr/bin/python3

# Atbash cipher in python

import string

def encode(input_string):
    key = list(string.ascii_lowercase)
    value = key[::-1]
    combine = list(zip(key,value))
    key_map = {k:v for (k,v) in combine}
    output_string = ''
    for char in input_string:
        if char in string.ascii_lowercase:
            output_string += key_map[char]
        elif char in string.ascii_uppercase:
            output_string += key_map[char.lower()].upper()
        else:
            output_string += char
    return output_string
    
if __name__ == '__main__':
    assert encode('gsrh rh zm vcznkov lu gsv zgyzhs xrksvi') == 'this is an example of the atbash cipher'
    assert encode('WIZARD') == 'DRAZIW'
