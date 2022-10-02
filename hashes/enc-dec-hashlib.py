import hashlib

print("\nHashLib Available Algorithms:\n------------------------------")
algos = list(hashlib.algorithms_guaranteed)

for i in range(0, 9):
	print(" [",i+1,"]",algos[i])
for i in range(9, len(algos)):
	print("[",i+1,"]",algos[i])
alo = int(input("\nEnter choice: "))

if alo>0 and alo<15:
	inp = input("Enter Plain text: ")
else:
	print("Enter the number left of the respective algorithm from the displayed output.")

if alo == 1:
	print("Encrypted Text: ",hashlib.sha256(inp.encode()).hexdigest())
elif alo == 2:
	print("Encrypted Text: ",hashlib.sha3_384(inp.encode()).hexdigest())
elif alo == 3:
	print("Encrypted Text: ",hashlib.sha224(inp.encode()).hexdigest())
elif alo == 4:
	print("Encrypted Text: ",hashlib.sha3_512(inp.encode()).hexdigest())
elif alo == 5:
	print("Encrypted Text: ",hashlib.sha1(inp.encode()).hexdigest())
elif alo == 6:
	print("Encrypted Text: ",hashlib.shake_256(inp.encode()).hexdigest())
elif alo == 7:
	print("Encrypted Text: ",hashlib.shake_128(inp.encode()).hexdigest())
elif alo == 8:
	print("Encrypted Text: ",hashlib.md5(inp.encode()).hexdigest())
elif alo == 9:
	print("Encrypted Text: ",hashlib.sha3_224(inp.encode()).hexdigest())
elif alo == 10:
	print("Encrypted Text: ",hashlib.sha3_256(inp.encode()).hexdigest())
elif alo == 11:
	print("Encrypted Text: ",hashlib.sha512(inp.encode()).hexdigest())
elif alo == 12:
	print("Encrypted Text: ",hashlib.blake2b(inp.encode()).hexdigest())
elif alo == 13:
	print("Encrypted Text: ",hashlib.sha384(inp.encode()).hexdigest())
elif alo == 14:
	print("Encrypted Text: ",hashlib.blake2s(inp.encode()).hexdigest())
print()