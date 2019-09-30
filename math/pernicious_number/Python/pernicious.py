'''This is a proposed brute force algorithm writtem in python 
to test whether a given input positive integer other than 1 and 2 
is a pernicious prime or not''' 

#OUTPUT FORMAT :- if pernicious number , output yes else no 
#INPUT FORMAT  :- A positive integer other than 1 and 2  

'''According to number theory , a positive number is pernicious number if 
sum of the digit of this number in binary form is prime'''

'''Basic Outline Of Algorithm:- We count the set bits of a number and check 
whether that count is prime or not'''


#################### Overall complexity is O(sqrt(n)*log(n))  ############################

import math


def isprime(num): #function to check whether a number is prime or not 

#A simple solution is to iterate through all numbers from 2 to n-1 
#and for every number check if it divides n. If we find any number that 
#divides, we return false. We can do following optimizations:
#Instead of checking till n, we can check till sqrt(n) because a larger 
#factor of n must be a multiple of smaller factor that has been already 
#checked.The algorithm can be improved further by observing that all 
#primes are of the form 6k + 1 or 6k - 1, with the exception of 2 and 3. 
#This is because all integers can be expressed as (6k + i) for some 
#integer k and for i = -1, 0, 1, 2, 3, or 4.This is because since 2 
#divides (6k + 0), (6k + 2), (6k + 4); and 3 divides (6k + 3). So a more 
#efficient method is to test if n is divisible by 2 or 3, then to check 
#through all the numbers of form 6k + 1 or 6k - 1	
	
        if num<3 or num==3:
		return 1
	if num%2==0 or num%3==0:
		return 0
	for i in range(5,int(math.sqrt(num))+1,6):
		if num%i==0 or num%(i+2)==0:
			return 0
	return 1		########## O(sqrt(n))		

def count_ones(num): #function to calculate the number of set bits in a number

#Loop through all bits in an integer, check if a bit is set and if it is 
#then increment the set bit count. But we can also do it in more efficient way :- 
#Subtraction of 1 from a number toggles all the bits (from right to left) till 
#the rightmost set bit(including the righmost set bit). So if we subtract a 
#number by 1 and do bitwise & with itself (n & (n-1)), we unset the righmost 
#set bit. If we do n & (n-1) in a loop and count the no of times loop executes 
#we get the set bit count.Beauty of the this solution is number of times it loops 
#is equal to the number of set bits in a given integer.
	count=0
	while num:
		num = (num&(num-1))
		count+=1

	return count	########## O(log(n))

while 1:

	num = input("Enter any positive integer: ") #other than 1 and 2 
	if num!=1 and num!=2:

		total_set_bits = count_ones(num) #since sum of set bits is equivalent to counting those bits 
		flag=isprime(total_set_bits)
		if flag==1:
			print "yes\n"
		else:
			print "no\n"	
	else:
		print "Please enter any number other tha 1 or 2\n"
