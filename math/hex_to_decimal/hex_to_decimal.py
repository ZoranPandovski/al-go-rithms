import binascii

num=binascii.unhexlify(str(input()))
endian=str(input("big or little? : "))

if endian=="little":
    num=num[::-1]
    print(int(binascii.hexlify(num).decode(),16))
else:
    print(int(binascii.hexlify(num).decode(),16))
