from math import log
from random import randrange

def isPrime(n):
    if n==2 or n==3: return True
    if n%2==0 or n<2: return False
    for i in range(3,int(n**0.5)+1,2):   # only odd numbers
        if n%i==0:
            return False

    return True

def generateLargePrime(k):
     #k is the desired bit length
     r=100*(log(k,2)+1) #number of attempts max
     r_ = r
     while r>0:
        #randrange is mersenne twister and is completely deterministic
        #unusable for serious crypto purposes
         n = randrange(2**(k-1),2**(k))
         r-=1
         if isPrime(n) == True:
             return n
     return "Failure after " + repr(r_) + " tries."

# print generateLargePrime(8)
