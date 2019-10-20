# -*- coding: utf-8 -*-
"""
Created on Tue Sep 25 20:50:17 2018

@author: Varshika Choudhary

--------------------------------
Input:
Enter the string: 

abc

Output:
Permutation of the string: 
abc
acb
bac
bca
cab
cba

---------------------------------
"""

import itertools

print("Enter the string: " )
s = input()
print()
print("Permutation of the string: " )
#k = int(k)
l = list(itertools.permutations(s))
l.sort()
for i in l:
    s = ''
    for f in i:
        s+=f
    print(s)