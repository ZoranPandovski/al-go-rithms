# First pick a number. 
# If it is odd, multiply it by three and add one; 
# if it is even, divide it by two. 
# Repeat this procedure until you arrive at one.

import strutils

proc collatz_chain(i : int) :seq[int] = 
  var n = i
  result= @[n]
  while not(n == 1):
    if n mod 2 == 0:
      n = n div 2
    else:
      n = (n * 3) + 1
    result.add(n)

when isMainModule:
  echo "Enter a number"
  let num =  readLine(stdin).parseInt()
  echo "collatz_chain for ", num, " is: "
  echo collatz_chain num
