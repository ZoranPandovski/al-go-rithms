# extended gcd and inverse mod
from math import gcd


def extgcd(a, b):
    if (abs(a) >= abs(b)):
        if a % b == 0:
            v1 = [b, 0, 1]
            return v1
        else:
            q = a // b
            r = a % b
            D, s, t = extgcd(b, r)
            v2 = [D, t, s - t*q]
            return v2
    else:
        return extgcd(abs(b), abs(a))

def modinv(a, n):    
    if (gcd(a, n) == 1):
        _, _, m = extgcd(a, n)
        return m % n 
