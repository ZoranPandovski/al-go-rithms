sum1=0                                            
num=int(input("Enter a number:")                # taking input from user
temp=num                                        # storing value of number in temporary variable as we need original later. 
while(num):                                     # loop to find the sum of "strong number" series
    i=1
    f=1
    r=num%10
    while(i<=r):
        f=f*i
        i=i+1
    sum1=sum1+f
    num=num//10
if(sum1==temp):                           # printing the result  
    print("The number is a strong number")
else:
    print("The number is not a strong number")
