#!/bin/python3

import math
import os
import random
import re
import sys

def diagonalDifference(arr,n):
    d1=d2=0
    for i in range(0,n):
        d1+=arr[i][i]
        d2+=arr[i][n-1-i]
    return abs(d2-d1)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    arr = []

    for _ in range(n):
        arr.append(list(map(int, input().rstrip().split())))

    result = diagonalDifference(arr,n)

    fptr.write(str(result) + '\n')

    fptr.close()
    
    
"""
Input (stdin)
3

11 2 4
4 5 6
10 8 -12

Output (stdout)
15
"""
