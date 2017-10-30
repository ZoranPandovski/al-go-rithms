from __future__ import division
from math import exp
import numpy as np
import sys

def poly_regression (arr_x, arr_y, k):
	#find the k-th degree regression polynomial using matrices
	#context: arr_x is a list of independent variables and arr_y is a list of dependent variables
	#constraint: arr_x and arr_y are of the same size, and the elements of arr_x are pairwise distinct
	#reference: https://www.varsitytutors.com/hotmath/hotmath_help/topics/quadratic-regression
	A1=[]
	for i in range (0, k + 1):
		temp=[]
		for m in range (0, k + 1):
			#the elements are in the form of sum of x^(2k-i-m)
			sum = 0
			for j in range (0, len(arr_x)):
				sum += (arr_x[j]) ** (2 * k - i - m)
			temp.append(sum)
		A1.append(temp)
	B1=[]
	for i in range (0, k + 1):
		for j in range (0, len(arr_x)):
			sum += (arr_x[j] ** (k - i)) * (arr_y[j]);
		B1.append(sum)
	A=np.array(A1)
	B=np.array(B1)
	#print (A)
	A_inv=np.linalg.inv(A)
	C=np.dot(A_inv, B)
	#C = [a_k, a_{k-1}, ...] represents a_kx^k+a_kx^(k-1)+...
	return C