import math
number = int(input("Enter any number: "))
count = 0
digit_sum = 0
for i in str(number):
    count += 1
for i in str(number):
    digit_sum += pow(int(i), count)

if digit_sum == number:
    print("The number is armstrong")
else:
    print("How about NOPE")
