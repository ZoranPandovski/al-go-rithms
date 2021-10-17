def gcd(a,b):
    if(b==0): 
        return a 
    else: 
        return gcd(b,a%b)
    
a = int(input("Enter the first integer: "))
b = int(input("Enter the second integer: "))
    
print("The greatest common denominator of " + str(a) + " and " + str(b) + " is: " + str(gcd(a,b)))
