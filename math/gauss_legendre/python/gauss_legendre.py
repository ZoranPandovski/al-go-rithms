
'''
From Wikipedia:
https://en.wikipedia.org/wiki/Gauss%E2%80%93Legendre_algorithm

"The Gauss–Legendre algorithm is an algorithm to compute the digits of pi.
It is notable for being rapidly convergent, with only 25 iterations producing
45 million correct digits of π. However, the drawback is that it is computer memory-intensive"

'''

import numpy as np


num_iter = 5

#Instantiate
#The values at each iteration are stored
a = np.zeros(num_iter+1)
b = np.zeros(num_iter+1)
t = np.zeros(num_iter+1)
p = np.zeros(num_iter+1)
pi = np.zeros(num_iter+1)

a[0] = 1.0
b[0] = 1/np.sqrt(2)
t[0] = 0.25
p[0] = 1.0

#Update on each iteration
for i in range(1, num_iter+1):
  a[i] = (a[i-1]+b[i-1])/2
  b[i] = np.sqrt(a[i-1]*b[i-1])
  t[i] = t[i-1]-p[i-1]*(a[i-1]-a[i])**2
  p[i] = 2*p[i-1]
  
  pi[i] = (a[i]+b[i])**2/(4*t[i])
  
  print("{0:.20f}".format(pi[i]))