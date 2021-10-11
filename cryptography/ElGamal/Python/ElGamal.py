from algo import mod_inv
from random import randrange, randint
from ecurves import *

def elgalmal_encrypt(M,k,a,p):
    '''
    Input:
          M - menssage
          k - recipient private key
          a - generator
          p - prime
    Output (c1,c2) [Encrypted]
    '''

    s = randrange(1,p-1)
    c1 = a**s
    c2 = m*((a**k)**s)
    return c1,c2

def elgamal_decrypt(c1,c2,k,p):
    '''
    Input:
        c1 - a^s
        c2 - m*(a^k)^s
        k - private key
        p - prime
    Output: c2*(c1^k)^-1 [Decrypted]
    '''

    s = pow(c1, k, p)
    return (c2*(mod_inv(s,p)))%p

def generateKey(curve):
    '''
    Input:
                      curve - Valid Curve
    Output: (Int, Point)
    '''
    privKey = randint(1, curve.p - 1)
    pubKey = privKey*curve.gen
    return privKey, pubKey

def ECEG_encrypt(curve, m, pubKey):
    '''
    Input:
                      curve - Valid Curve
                      m - message
                      pubKey - Public Key
    Output: (Point, Point)
    '''
    r = randint(1, curve.p - 1)
    c1 = r*curve.gen
    c2 = (r*pubKey) + m
    return (c1, c2)

def ECEG_decrypt(curve, c1, c2, privKey):
    '''
    Input:
                      curve - Valid Curve
                      (c1, c2) - Ciphered  Text
                      privKey - Private Key
    Output: Point
    '''
    m = c2 - (privKey*c1)
    return m

def ECEG_test():
    c = EC(317689081251325503476317476413827693272746955927, \
            79052896607878758718120572025718535432100651934, \
            785963102379428822376694789446897396207498568951)
    gen = Point(c, 771507216262649826170648268565579889907769254176, \
            390157510246556628525279459266514995562533196655)
    c.gen = gen
    KprivBob, KpubBob = generateKey(c)

    # What alice does
    m = 10301*gen
    print("Plain Text = " + str(m))
    ciphered = ECEG_encrypt(c, m, KpubBob)
    # print("Cipher Text = " + "(" + ','.join(str(x) for x in ciphered) + ")")
    # Bob decrypts the message
    m_prime = ECEG_decrypt(c, ciphered[0], ciphered[1], KprivBob)
    print("Decrypted  = " + str(m_prime))
