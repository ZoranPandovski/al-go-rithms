'''merge sort routine written by me two years back when I started learning
 algorithms.This is special because it took me 2-3 days to write this and was 
 my first algo problem that I solved'''
from __future__ import print_function

def merge_sort(lst):
	n=len(lst)
	if n<=1:
		return lst
	else:
		mid=int(n/2)
		first_half=lst[:mid]
		second_half=lst[mid:]
		A=merge_sort(first_half)
		B=merge_sort(second_half)
		i=0
		j=0
		C=[]
		p=len(first_half)
		q=len(second_half)
		while i<p and j<q:
			if A[i]<B[j]:
				C.append(A[i])
				i+=1
			else :
				C.append(B[j])
				j+=1
		if i==p:
			C=C+B[j:]
		else:
			C=C+A[i:]
						
			
		return C

import random
new_list=[]
for x in range (0, 100000000):
    new_list.append(random.randint(0, 9999999999999))
    
print(len(new_list))

a=merge_sort(new_list)
print(a)



