#
#   author = @AKS1996
#

def mGCD(a,b,m=1):
    """
        Calculates very large GCD
        Uses squaring for calculating residue
        Complexity: O(log(n))
    """
    a1 = a%m
    p = 1
    while b > 0:
         if b%2 ==1:
             p *= a1
             p = p%m
         b /= 2
         a1 = (a1 * a1)%m

    return p

# print(mGCD(5,55,221))
