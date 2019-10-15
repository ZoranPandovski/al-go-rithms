#Greatest common divisor
def gcd(a, b):
    if(a%b == 0):
        return b
    else:
        return gcd(b, a%b)
        
