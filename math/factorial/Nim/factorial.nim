from strutils import parseInt

proc fact(n: int): float =
  case n
    of 0: result = 1.0
    else:
      result = float(n) * fact(n-1)

when isMainModule:
  echo "Enter a number"
  let num = readLine(stdin).parseInt()
  echo fact(num)
