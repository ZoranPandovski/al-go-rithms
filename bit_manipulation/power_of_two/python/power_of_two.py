# Check if given number is power of 2 or not  
  
# Function to check if x is power of 2 
def isPowerOfTwo (x): 
  
    # First x in the below expression is for the case when x is 0  
    return (x and (not(x & (x - 1))) ) 
  
# Driver code 
x = int(input("Enter a no:"))
if(isPowerOfTwo(x)): 
    print('Yes') 
else: 
    print('No') 
