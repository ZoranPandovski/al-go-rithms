
import sys

def selection_sort(items):
    """Implementation of the selection sort algorithm using Python
    inside parameter we can pass some items which are heterogeneous
    comparable
    Example:
    
   C:\Users\Hp\Desktop> python selectionsortorfi.py
   Enter numbers separated by a comma:
   7,5,8,3,2
   [2, 3, 5, 7, 8]
   by d78ui98
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


if __name__ == '__main__':
    # to make it work on both version python 2.x and 3.x 
    if sys.version_info.major > 3:
        input_fun = input   
    else:
        input_fun = raw_input

    user_input = input_fun('Enter numbers separated by a comma:\n')
    unsorted = [int(item) for item in user_input.split(',')]
    print(selection_sort(unsorted))
