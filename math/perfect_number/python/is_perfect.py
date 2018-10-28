#!/usr/bin/python3

#Written by Grant Hill

from math import sqrt

def divisorsum(num):
    divsum = 0
    for i in range(1, int(sqrt(num))): #You only have to calculate up to the square rot of the number.
        if num % i == 0:
            divsum += i
            divsum += num // i
    return divsum - num #Don't count the number itself when you're calculating the sum of its divisors. 

def is_perfect(num):
    return num == divisorsum(num)
