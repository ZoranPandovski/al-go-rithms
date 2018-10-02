from strutils import parseInt

proc gcd(x, y: int): int =
  if x == 0:
    return y
  result = gcd(y mod x, x)

proc euler_totient(n: int): int =
  result = 1
  for i in 2..< n:
    if gcd(n,i) == 1:
      inc result

when isMainModule:
  echo "Enter a number"
  let num = readLine(stdin).parseInt()
  echo euler_totient(num)
