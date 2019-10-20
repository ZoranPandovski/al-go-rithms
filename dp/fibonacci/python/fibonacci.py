#!/usr/bin/python3
"""
This module contains a simple implemenation of the algorithm to determine
the n-th fibonacci number, using dynamic programming. The previous fibonacci
numbers are calculated once and stored in a dictionary.

Doctests included. To use algorithm, please follow examples in docstring
"""


class Fib():
    """
    Fib class
    """
    fib_dict = {0: 0, 1: 1}
    def fib(self, n=None):
        """
        Find n-th fibonacci number

        :param int n: the position of the desired fib number
        :return: the n-th fibonacci number
        :rtype: int

        DOCTESTS
        --------
        >>> f = Fib()
        
        Test 1 (n = 1):
        >>> print(f.fib(1))
        1
        
        Test 2 (n = 2):
        >>> print(f.fib(2))
        1
        
        Test 3 (n = 50):
        >>> print(f.fib(50))
        12586269025
        
        Test 4 (n = 200);
        >>> print(f.fib(200))
        280571172992510140037611932413038677189525
        
        Test 5 (n = None)
        >>> print(f.fib())
        Traceback (most recent call last):
            ...
        TypeError: param @n must be an int
        
        Test 6 (n = -1)
        >>> print(f.fib(-1))
        Traceback (most recent call last):
            ...
        ValueError: param @n must be greater than or equal to 0
        """
        
        if type(n) is not int:
            raise TypeError("param @n must be an int")
        if n < 0:
            raise ValueError("param @n must be greater than or equal to 0")
        
        if n in self.fib_dict:
            return self.fib_dict[n]
        else:
            fn = self.fib(n - 1) + self.fib(n - 2)
            self.fib_dict[n] = fn
            return fn

if __name__ == '__main__':
    import doctest
    doctest.testmod()
