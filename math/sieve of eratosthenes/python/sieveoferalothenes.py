#about the algorithm-The sieve of Eratosthenes is one of the most efficient ways to find all primes smaller than n when n is smaller than 10 million or soThe sieve of Eratosthenes is one of the most efficient ways to find all primes smaller than n when n is smaller than 10 million or so.
#The algorithm is very fast- time complexity of the algorithm- O(n).
#this progran will check for prime numbers to a certain range and if the prime is prime it will display True else False
import math
n=int(input("Enter the number\t"))
isPrime=[]
for i in range(0,n,1):
    isPrime.append(True) #assigning the array to False uptil n
isPrime[0]=False
isPrime[1]=False
for i in range(2,int(math.sqrt(n))+1,1):
    for j in range(2*i,n,i): #checking for prime numbers
        isPrime[j]=False
count_prime=0
for i in range(1,n,1):
    if isPrime[i]==True:
        count_prime+=1
    print(i,":",isPrime[i])
print("The number of prime numbers upto the chosen range is",count_prime)