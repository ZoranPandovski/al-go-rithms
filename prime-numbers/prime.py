value = int(input("Enter the value..."))
count = 0
print("The prime numbers till ", value ," are ")
for i in range(2,value):
	for j in range(2,value):
		if(i%j == 0 and i!=j):
			count = count + 1
	if count < 1:
		print(i)
	count = 0