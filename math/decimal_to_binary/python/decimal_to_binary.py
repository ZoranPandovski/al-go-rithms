def decimal_to_binary(n):
    if n > 1: decimal_to_binary(n//2)
    print(n % 2, end = '')

try: decimal_to_binary(int(input("Enter an Integer to Covert into Binary: ")))
except ValueError: print("Input is not an integer.")
print()
