def gcd(a, b):
    while b:
        a, b = b, a%b
    return a
# You test with the input form the keyboard
if __name__ == "__main__":
    a = int(input("Please give me the first number: "))
    b = int(input("Please give me the second number: "))
    print("GCD(",a, ",", b, ") =", gcd(a, b));
