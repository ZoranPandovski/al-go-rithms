import strutils

proc sum_digits(n: int): int =
  for c in $ n:
    result += parseInt($ c)

when isMainModule:
  echo "Enter a number"
  let num = readLine(stdin).parseInt()
  echo "Sum of digits is: ", sum_digits(num)
