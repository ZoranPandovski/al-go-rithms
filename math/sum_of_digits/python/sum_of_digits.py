#!/usr/bin/python3

def sum_of_digits(number, base=10):
    '''Calculates the sum of the base base (default 10) digits in number.

    >>> sum_of_digits(123)
    6
    >>> sum_of_digits(123, 16)
    18
    '''
    running_sum = 0
    while number > 0:
        number, digit = divmod(number, base)
        running_sum += digit
    return running_sum
