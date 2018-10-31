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


