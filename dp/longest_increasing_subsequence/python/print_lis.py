# -*- coding: utf-8 -*-
"""
Created on Sat Oct 20 13:25:12 2018

@author: Varshika Choudhary

-----------------------------------
Input:
enter no. of test cases:
1
enter elements of array: 
9 
22 9 33 43 54 8 90 60 65

Output:
length of LIS is:  6
22 33 43 54 60 65
------------------------------------

"""

print("enter no. of test cases:")
t = int(input())
while t:
    t= t-1
    print("enter elements of array: ")
    n = int(input())
    arr = list(map(int,input().split()))
    lis = [1]*n
    index = [0]*n
    
    maximum = 0
    
    for i in range(1,n):
        for j in range(0,i):
            if arr[i] > arr[j] and lis[i] < lis[j] +1:
                lis[i] = lis[j] +1
                index[i] = j
    
    
    for k in range(1,n):
        maximum = max(maximum, lis[k])
    
    print("length of LIS is: ",maximum)
    
    res = []
    res.append(arr[i])
    while i != 0:
        res.append(arr[index[i]])
        i = index[i]
        
    print(" ".join(str(x) for x in reversed(res)))