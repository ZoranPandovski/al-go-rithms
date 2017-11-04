
import sys

def selection_sort(items):
    """Implementation of the selection sort algorithm using Python
    inside parameter we can pass some items which are heterogeneous
    comparable
    """

    length = len(items)
    for i in range(length):
        least = i
        for j in range(i + 1, length):
            if items[j] < items[least]:
                least = j
        items[least], items[i] = (
            items[i], items[least]
        )
    return items

def test():
    array = [2, 10, 7, 1]
    assert selection_sort(array) == [1, 2, 7, 10]

if __name__ == '__main__':
    test()
