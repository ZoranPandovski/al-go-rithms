import strutils

proc gcd(x, y: int): int =
    if x == 0:
      return y
    gcd(y mod x, x)

proc lcm(x, y: int): int =
    return x * y div gcd(x, y)

when isMainModule:
    echo "Enter first number"
    let num1 = readLine(stdin).parseInt()
    echo "Enter second number"    
    let num2 = readLine(stdin).parseInt()
    echo "LCM: ", lcm(num1, num2)
