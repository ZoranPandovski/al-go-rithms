value = int(input("Enter a value..."))
x1 = -1
x2 = 1
x3 = 0
print("The fibonacci series is...")
for x in range(value):
	x3 = x1 + x2
	x1 = x2
	x2 = x3
	print(x3)