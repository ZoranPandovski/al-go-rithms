from __future__ import print_function
def sum_of_digits(n):
    sum = 0
    for i in str(n):
        sum += int(i)
        
    return sum

print(sum_of_digits(3))  #3
print(sum_of_digits(3454332)) #24
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
