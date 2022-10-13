"""               SQUARE Matrix Multiplication

Matrix multiplication is a binary operation that produces a matrix from two matrices.
For matrix multiplication, the number of columns in the first matrix must be
equal to the number of rows in the second matrix.

The resulting matrix, known as the matrix product, has the number of rows of the
first and the number of columns of the second matrix.

Let A be a m x n matrix and B be a n x p matrix then the matrix C ,where

            C =A.B

is defined as cij = Ai1.B1j + Ai2.B2j +...+ Ain.Bnj

"""

import numpy as np  #Importing Numpy Library

n=int(input())   #no.of rows/columns in the matrices

A=[]     #Array input from user one row at a time in the form of comma separated values.

for i in range(n):
    
    a= [ ]
    
    for num in input().split(','):
        
        a.append(int(num))
        
    A.append(a)

# Coversion of Array into n x n matrix for both Aand B
    
B=[]

for i in range(n):
    
    b= [ ]
    
    for num in input().split(','):
        
        b.append(int(num))
        
    B.append(b)


X=np.mat(A)
Y=np.mat(B)
Z=X*Y
z=np.array(Z)
from array import *
def array_list(z):
    m = z.tolist() # list
    print(*m ,sep=",")
    
for i in range(n):
    array_list(z[i])

"""
TEST CASE 1:
>>> 
2
1,2
3,4
5,6
7,8

OUTPUT:
19,22
43,50

TEST CASE 2:
>>>
3
1,2,3
4,5,6
7,8,9
10,11,12
13,14,15
16,17,18

OUTPUT:
84,90,96
201,216,231
318,342,366

"""
