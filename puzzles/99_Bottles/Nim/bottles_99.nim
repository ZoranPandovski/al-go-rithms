from strformat import fmt

proc lyric_99_bottles(num: int) =
  if num == 99:
    echo "99 bottles of beer on the wall, 99 bottles of beer."
  elif num == 0:
    echo "Take one down and pass it around, no more bottles of beer on the wall."
    echo "No more bottles of beer on the wall, no more bottles of beer."
    echo "Go to the store and buy some more, 99 bottles of beer on the wall."
    return
  else:
    echo fmt"Take one down and pass it around, {num} bottles of beer on the wall."
    echo fmt"{num} bottles of beer on the wall, {num} bottles of beer."

  lyric_99_bottles(num - 1)


lyric_99_bottles(99)
