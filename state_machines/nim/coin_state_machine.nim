var state = 0

while state != 25:
  echo "Balance: " , state
  echo "Insert a coin (penny, nickel, dime, quarter)"

  let coin = readLine(stdin)

  case coin
    of "penny":
      state += 1
    of "nickel":
      state += 5
    of "dime":
      state += 10
    of "quarter":
      state += 25
    else:
      echo "Not a coin"

echo "Here's your quarter"
