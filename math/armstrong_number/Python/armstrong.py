n = str(input("Enter Number: "))
s = 0
for i in n:
    s = s + int(i)**3
if(s == int(n)):
    print("Number is armstrong.")
else:
    print("Number is not armstrong.")
