import math

x = int(input("Digit your number: "))

if(math.sqrt(x)%1==0):
    print("This number is an perfect square")
else:
    print("This number is not an perfect square")

