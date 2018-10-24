from fractions import Fraction
import math

# Fibonacci recursive greedy algorithm
def FibonacciAlgorithm(fraction):
    numerator = fraction.numerator
    denominator = fraction.denominator
    if numerator == 1:
        return [fraction]
    else:
        ceil_den_num = math.ceil(denominator / numerator)
        left_frac = Fraction(1, ceil_den_num)
        right_frac = Fraction((-denominator) % numerator,
                              (denominator * ceil_den_num))
        recursion = FibonacciAlgorithm(right_frac)
        return [left_frac] + recursion

# Example execution:
# FibonacciAlgorithm(Fraction(9, 32))
