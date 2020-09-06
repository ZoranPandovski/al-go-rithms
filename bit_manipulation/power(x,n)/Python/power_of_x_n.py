# //Finding power of x to the n, where n can be a positive or negative integer.
# //As we already we know that negative exponent is equal to 1 by power(x,n)
# //And this is a iterative approach

# //Problem link: https://leetcode.com/problems/powx-n/

# /**********************************
#  * Dry Run of Program:
#  * power(2.0,10)=(2*2)^5 = 4^5 =1024
#  * 4^5 = 4*4^4 = 1024
#  * 4^4 = (4*4)^2 = 16^2 = 256
#  * 16^2 = (16*16) = 256^1 =256
#  * 256^1 = 256*256^0 = 256
# ***********************************/

def power(x,n):
    ans=1.0
    nn=n
    if nn<0:
        nn=-1*nn
    while(nn):
        if(nn%2 == 1):
            ans=ans*x
            nn=nn-1
        else:
            x=x*x
            nn=nn//2
    if(n<0):
        ans=((1.0)/ans)
    return ans


def main():
    x=eval(input())
    n=int(input())
    print(power(x,n))

main()