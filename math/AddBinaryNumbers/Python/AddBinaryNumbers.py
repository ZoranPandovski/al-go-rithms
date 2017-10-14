number1 = input("Enter the first number: ")
number2 = input("Enter the second number: ")

result = (int(number1, 2) + int(number2, 2))

result = bin(result)

print(result[2:])

