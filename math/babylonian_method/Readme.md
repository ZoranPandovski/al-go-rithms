#Babylonian Method

The iterative method for finding square roots is called the Babylonian method.

#Algorithm

1)Start with an arbitrary positive start value x (the closer to the 
   root, the better).
2)Initialize y = 1.
3) Do following until desired approximation is achieved.
  a) Get the next approximation for root using average of x and y
  b) Set y = n/x


#Example

n = 4 /*n itself is used for initial approximation*/
Initialize x = 4, y = 1
Next Approximation x = (x + y)/2 (= 2.500000), 
y = n/x  (=1.600000)
Next Approximation x = 2.050000,
y = 1.951220
Next Approximation x = 2.000610,
y = 1.999390
Next Approximation x = 2.000000, 
y = 2.000000
Terminate as (x - y) > e now.