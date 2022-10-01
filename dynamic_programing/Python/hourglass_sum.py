#!/bin/python3

import math
import os
import random
import re
import sys


def hourglassSum(arr):
    end = 3
    hourglass = [[0]*3]*3
    for ip in range(3):
        for pi in range(3):
            hourglass[ip][pi]=0
    suum1=0
    temp_sum=0
    for i in range(0,end+1):
        for j in range(0,end+1):
            begin = i
            center_index_i = begin+1
            center_index_j = end//2+j
            center_ele = arr[center_index_i][center_index_j]
            temp_sum = temp_sum + arr[center_index_i -1][center_index_j -1] + arr[center_index_i +1][center_index_j +1]+arr[center_index_i +1][center_index_j -1]+arr[center_index_i -1][center_index_j +1]+arr[center_index_i][center_index_j -1]+arr[center_index_i][center_index_j +1]+center_ele
            
            
            #print(center_index_i-1,center_index_j-1," ",center_index_i-1,center_index_j," ",center_index_i-1,center_index_j+1)
            #print(0,0," ",center_index_i,center_index_j," ",0,0)
            #print(center_index_i+1,center_index_j-1," ",center_index_i+1,center_index_j," ",center_index_i+1,center_index_j+1)
            
            print(arr[center_index_i-1][center_index_j-1]," ",arr[center_index_i-1][center_index_j]," ",arr[center_index_i-1][center_index_j+1])
            print(0," ",arr[center_index_i][center_index_j]," ",0)
            print(arr[center_index_i+1][center_index_j-1]," ",arr[center_index_i+1][center_index_j]," ",arr[center_index_i+1][center_index_j+1])
            print('sum of above is',temp_sum)
            if temp_sum > suum1:
                suum1 = temp_sum
                hourglass[0][0] = arr[center_index_i-1][center_index_j-1]
                hourglass[0][1] = arr[center_index_i-1][center_index_j]
                hourglass[0][2] = arr[center_index_i-1][center_index_j+1]
                hourglass[1][1] = arr[center_index_i][center_index_j]
                hourglass[2][0] = arr[center_index_i+1][center_index_j-1]
                hourglass[2][1] = arr[center_index_i+1][center_index_j]
                hourglass[2][2] = arr[center_index_i+1][center_index_j+1]
            #print(suum1)
            temp_sum = 0
    print(suum1)   
    return hourglass

        

ar2 = [[-9,0,-9,0,0,0],
       [-9,-9,-9,0,0,0],
       [-9,0,-9,8,0,-1],
       [1,4,1,6,-2,-2],
       [1,3,2,6,0,0,-4],
       [1,2,3,0,0,0]]


r = hourglassSum(ar2)

for i in range(len(r)):
  for j in range(len(r)):
    print(r[i][j])

