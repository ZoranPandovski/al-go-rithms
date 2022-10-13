#!/usr/bin/env python3
# 19BCE245 - Aayush Shah

def byte_stuff_msg(message,flag_seq,esc_seq):
#	stuffed_message = message.replace(esc_seq, esc_seq+esc_seq).replace('011111', esc_seq+'011111')
#	stuffed_message = message.replace(esc_seq, esc_seq+esc_seq).replace(flag_seq, esc_seq+flag_seq)
#	stuffed_message = message.replace(esc_seq, esc_seq+esc_seq)
#	print('after removing esc seq',message)
#	stuffed_message = message.replace(flag_seq, esc_seq+flag_seq)
#	print('after removing flag seq',message)
#	return stuffed_message
	return message.replace(esc_seq, esc_seq+esc_seq).replace(flag_seq, esc_seq+flag_seq)

def byte_unstuff_msg(message,flag_seq,esc_seq):
#	unstuffed_message = message.replace(esc_seq+'0111110', flag_seq).replace(esc_seq+esc_seq,esc_seq)
#	unstuffed_message = message.replace(esc_seq+flag_seq, flag_seq).replace(esc_seq+esc_seq,esc_seq)
#	temp = message.replace(esc_seq+flag_seq,flag_seq)
#	print('\t\t\t\t\t1',temp)
#	temp = temp.replace(esc_seq+esc_seq, esc_seq)
#	print('\t\t\t\t\t2',temp)
#	return temp
	return message.replace(esc_seq+flag_seq,flag_seq).replace(esc_seq+esc_seq, esc_seq)

def bit_stuff_msg(message,flag_seq):
#	flag_seq = '011111'
#	count = 0
#	stuffed_message = ''
#	for char in message:
#		stuffed_message += char
#		if flag_seq[count]==char:
#			count+=1
#		else:
#			count=0
#		if count==6:
#			stuffed_message += '0'
#			count = 0
#	print('1 : ',stuffed_message)
#	print('2 : ',message.replace('011111', '0111110'))
	
#	return stuffed_message
	flag_seq = '011111'
	return message.replace(flag_seq, '0111110')
	
def bit_unstuff_msg(message,flag_seq):
	flag_seq = '011111'
	return message.replace(flag_seq+'0', flag_seq)


#message = input('Enter the messsage : ')
#flag_seq = input('Enter the flag : ')
#esc_seq = input('Enter the ESC : ')

message = '01111110asdfsdf011111100111111001111110abcabcasdfasdfasdfabc'
flag_seq = '01111110'
esc_seq = 'abc'
print('Original          : ',message)

#bin_data = ' '.join(format(ord(x), 'b') for x in message)
#decoded = "".join([chr(int(binary, 2)) for binary in bin_data.split(" ")])

bit_stuffed_msg = bit_stuff_msg(message, flag_seq)
print('BIT stuffing      : ',bit_stuffed_msg)

bit_unstuffed_msg = bit_unstuff_msg(bit_stuffed_msg, flag_seq)
print('BIT unstuffing    : ',bit_unstuffed_msg)

byte_stuffed_msg = byte_stuff_msg(message, flag_seq,esc_seq)
print('BYTE stuffing     : ',byte_stuffed_msg)

byte_unstuffed_msg = byte_unstuff_msg(byte_stuffed_msg, flag_seq,esc_seq)
print('BYTE unstuffing   : ',byte_unstuffed_msg)

print('Are bit unstuffed, byte unstuffed and original strings same :',bit_unstuffed_msg==byte_unstuffed_msg==message)


"""
simplified : 
#!/usr/bin/env python3

def byte_stuff_msg(message,flag_seq,esc_seq):
	return message.replace(esc_seq, esc_seq+esc_seq).replace(flag_seq, esc_seq+flag_seq)

def byte_unstuff_msg(message,flag_seq,esc_seq):
	return message.replace(esc_seq+flag_seq,flag_seq).replace(esc_seq+esc_seq, esc_seq)

def bit_stuff_msg(message,flag_seq):
	flag_seq = '011111'
	return message.replace(flag_seq, '0111110')
	
def bit_unstuff_msg(message,flag_seq):
	flag_seq = '011111'
	return message.replace(flag_seq+'0', flag_seq)

message = '01111110asdfsdf011111100111111001111110abcabcasdfasdfasdfabc'
flag_seq = '01111110'
esc_seq = 'abc'
print('Original          : ',message)

#bin_data = ' '.join(format(ord(x), 'b') for x in message)
#decoded = "".join([chr(int(binary, 2)) for binary in bin_data.split(" ")])

bit_stuffed_msg = bit_stuff_msg(message, flag_seq)
print('BIT stuffing      : ',bit_stuffed_msg)

bit_unstuffed_msg = bit_unstuff_msg(bit_stuffed_msg, flag_seq)
print('BIT unstuffing    : ',bit_unstuffed_msg)

byte_stuffed_msg = byte_stuff_msg(message, flag_seq,esc_seq)
print('BYTE stuffing     : ',byte_stuffed_msg)

byte_unstuffed_msg = byte_unstuff_msg(byte_stuffed_msg, flag_seq,esc_seq)
print('BYTE unstuffing   : ',byte_unstuffed_msg)

print('Are bit unstuffed, byte unstuffed and original strings same :',bit_unstuffed_msg==byte_unstuffed_msg==message)


#!/usr/bin/env python3




message = '01111110asdfsdf011111100111111001111110abcabcasdfasdfasdfabc'
bin_data = ' '.join(format(ord(x), 'b') for x in message)
decoded = "".join([chr(int(binary, 2)) for binary in bin_data.split(" ")])

print(message)
print(bin_data)
print(decoded)

"""