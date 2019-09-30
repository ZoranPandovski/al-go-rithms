#! /usr/bin/env python3
# Program to depict the RSA Encryption/Decryption scheme
# Taken from the wikipedia page for RSA
import random

def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)


def enc_key(modulus, totient):
# The only requirement for the encryption key(e) is for it
# to be coprime to the totient.
    key = random.randint(2, totient - 1)

    while gcd(key, totient) != 1:
        key = random.randint(2, totient - 1)

    return key

def dec_key(enc_key, totient):
# We need to find the decryption key (d) such that,
# (e*d) mod totient = 1
# We use the extended Euclid algorithm for that.
# Code taken from the wikipedia page of Extended Euclid Algorithm
    t = 0
    newt = 1
    r = totient
    newr = enc_key

    while newr != 0:
        quotient = r // newr
        t, newt = newt, t - quotient * newt
        r, newr = newr, r - quotient * newr

    if r > 1:
        raise ValueError("Encryption Key: {} is not invertible".format(enc_key))
    if t < 0:
        t += totient

    return t


# p and q are the two primes
p = 11
q = 17

N = p * q
phi = (p - 1) * (q - 1) # phi is also called the totient.

e = enc_key(N, phi)
d = dec_key(e, phi)
# Message unit (m) should satisfy m < N.
# For larger messages, we break into chunks so that 
# the constraint is satisfied
message = random.randint(1, N - 1) # Original Message

cipher = (message ** e) % N # Encrypted Message
plain = (cipher ** d) % N # message decrypted
assert(message == plain)
