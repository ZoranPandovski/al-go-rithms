--Tested with Lua 5.3.4
io.write("How many Fibonacci numbers do you want? ")
n = io.read("*n")
f1=0
f2=1
for i=1, n do
  temp = f1 + f2
  print(temp)
  f1 = f2
  f2 = temp
end

