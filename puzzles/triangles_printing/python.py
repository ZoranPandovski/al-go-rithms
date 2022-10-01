# range
r = 9
bound = round(r/2)

for y in range(r):
  for x in range(r):
    if (x >= bound-y and x <= bound+y):
      print("*", end='')
    else:
      print(" ", end='')
  print();
