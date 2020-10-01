"""
This is a pure python implementation of the bogosort algorithm
For doctests run following command:
python -m doctest -v bogosort.py
or
python3 -m doctest -v bogosort.py
For manual testing run:
python bogosort.py
"""

from __future__ import print_function
import random


def bogosort(collection):
    """Pure implementation of the bogosort algorithm in Python
    :param collection: some mutable ordered collection with heterogeneous
    comparable items inside
    :return: the same collection ordered by ascending
    Examples:
    >>> bogosort([0, 5, 3, 2, 2])
    [0, 2, 2, 3, 5]
    >>> bogosort([])
    []
    >>> bogosort([-2, -5, -45])
    [-45, -5, -2]
    """

    def isSorted(collection):
        if len(collection) < 2:
            return True
        for i in range(len(collection) - 1):
            if collection[i] > collection[i + 1]:
                return False
        return True

    while not isSorted(collection):
        random.shuffle(collection)
    return collection

if __name__ == '__main__':
    try:
        raw_input          # Python 2
    except NameError:
        raw_input = input  # Python 3

    user_input = raw_input('Enter numbers separated by a comma:\n').strip()
    unsorted = [int(item) for item in user_input.split(',')]
    print(bogosort(unsorted))
