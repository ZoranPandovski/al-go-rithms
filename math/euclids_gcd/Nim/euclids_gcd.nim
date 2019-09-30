import strutils

proc gcd(x, y: int): int =
    if x == 0:
      return y
    gcd(y mod x, x)

when isMainModule:
    echo "Enter first number"
    let num1 = readLine(stdin).parseInt()
    echo "Enter second number"    
    let num2 = readLine(stdin).parseInt()
    echo "GCD: ", gcd(num1, num2)
