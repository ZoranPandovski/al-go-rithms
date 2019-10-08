FIXED_IP = [2, 6, 3, 1, 4, 8, 5, 7]
FIXED_IP = [2, 6, 3, 1, 4, 8, 5, 7]
FIXED_EP = [4, 1, 2, 3, 2, 3, 4, 1]
FIXED_IP_INVERSE = [4, 1, 3, 5, 7, 2, 8, 6]
FIXED_P10 = [3, 5, 2, 7, 4, 10, 1, 9, 8, 6]
FIXED_P8 = [6, 3, 7, 4, 8, 5, 10, 9]
FIXED_P4 = [2, 4, 3, 1]
S0 = [[1, 0, 3, 2],
 [3, 2, 1, 0],
 [0, 2, 1, 3],
 [3, 1, 3, 2]]
S1 = [[0, 1, 2, 3],
 [2, 0, 1, 3],
 [3, 0, 1, 0],
 [2, 1, 0, 3]]
KEY = '0111111101'
def permutate(original, fixed_key):
 new = ''
 for i in fixed_key:
     new += original[i - 1]
 return new
def left_half(bits):
 return bits[:(len(bits)) // 2]
def right_half(bits):
 return bits[len(bits) // 2:]
def shift(bits):
 rotated_left_half = left_half(bits)[1:] + left_half(bits)[0]
 rotated_right_half = right_half(bits)[1:] + right_half(bits)[0]
 return rotated_left_half + rotated_right_half
def key1():
 print(' Generating Key1')
 return permutate(shift(permutate(KEY, FIXED_P10)), FIXED_P8)
def key2():
 print(' Generating Key2')
 return permutate(shift(shift(permutate(KEY, FIXED_P10))), FIXED_P8)
def xor(bits, key):
 new = ''
 for bit, key_bit in zip(bits, key):
     new += str(((int(bit) + int(key_bit)) % 2))
 return new
def lookup_in_sbox(bits, sbox):
 row = int(bits[0] + bits[3], 2)
 col = int(bits[1] + bits[2], 2)
 return '{0:02b}'.format(sbox[row][col])
def f_k(bits, key):
 L = left_half(bits)
 R = right_half(bits)
 bits = permutate(R, FIXED_EP)
 print(" E/P output = " + bits)
 print(" Key = " + key)
 bits = xor(bits, key)
 bits = lookup_in_sbox(left_half(bits), S0) + lookup_in_sbox(right_half(bits), S1)
 bits = permutate(bits, FIXED_P4)
 print(" P4 = " + bits)
 return xor(bits, L)
def encrypt(plain_text):
 print("Plain Text: " + plain_text)
 bits = permutate(plain_text, FIXED_IP)
 print("Initial Permutation = " + bits)
 print("Round function 1 ")
 temp = f_k(bits, key1())
 bits = right_half(bits) + temp
 print("Round function 2 ")
 bits = f_k(bits, key2())
 print("Cipher Text = " + permutate(bits + temp, FIXED_IP_INVERSE))
def decrypt(cipher_text):
 print("Cipher Text: " + cipher_text)
 bits = permutate(cipher_text, FIXED_IP)
 print("Initial Permutation = " + bits)
 print("Round function 1 ")
 temp = f_k(bits, key2())
 bits = right_half(bits) + temp
 print("Round function 2 ")
 bits = f_k(bits, key1())
 print("Plain Text = " + permutate(bits + temp, FIXED_IP_INVERSE))
if __name__== "__main__":
 encrypt('11101010')
 decrypt('00000110')
