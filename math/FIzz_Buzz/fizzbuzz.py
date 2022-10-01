#This program prints 'fizz' if a number within the given range is divisible by 3, 'buzz' if the number is divisible by 5 and 'fizzbuzz' the number is divisible by both 3&5.

min = int(input("Enter minimum for range : "))
max = int(input("Enter maximum for range : "))
for num in range(min,max+1):
    string = ""
    if num % 3 == 0:
        string = string + "Fizz"
    if num % 5 == 0:
        string = string + "Buzz"
    if num % 5 != 0 and num % 3 != 0:
        string = string + str(num)
    print(string)
