#Comparison of different time complexities.

#####################
#constant time - O(1)
#####################
def constant(n):
    result = n * n
    return result


##############################
#Logarithmic time - O(log(n))
##############################

def logarithmic(n):
    result = 0
    while n > 1:
        n // 2
        result += 1
    return result

###################
#Linear Time - O(n)
###################
def linear(n,A):
    for i in range(n):
        if A[i] == 0:
            return 0
    return 1


#########################
# Quadratic time - O(n^2)
#########################
def quadratic(n):
    result = 0
    for i in range(n):
        for j in range(1, n):
            result += 1
    return result

#########################
# Exponential time - O(2^n)
#########################
def exponential(n, peg_from="A", peg_to="C", spare_peg="B"):
    #Solving the tower of hanoi problem (Try here:  https://emerzon1.github.io/TowerOfHanoi/) takes 2^n-1 moves where n is the amount of disks
    if n < 1:
        return None
    if n > 1:
        exponential(n-1, peg_from, spare_peg, peg_to)
    print("Move top disk from peg " + peg_from + " to peg " + peg_to)
    if n > 1: 
        exponential(n-1, spare_peg, peg_to, peg_from)
    
