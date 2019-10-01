# Returns 0 if n is even, else odd 
def isEven(n) : 
       
    # n&1 is 1, then odd, else even 
    return (n & 1) 
   
# Driver code 

n = int(input("Enter a no:"))
if(isEven(n) == 0) : 
    print ("Even") 
else : 
    print ("Odd") 
