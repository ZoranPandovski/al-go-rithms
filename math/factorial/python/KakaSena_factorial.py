n = int(input("Enter a number: "))
fact = 1
  
for i in range(1, n+1): 
    fact = fact * i

print ("The factorial of", str(n) , "is: ",end="") 
print (fact)