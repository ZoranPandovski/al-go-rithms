def bubble_sort(data):
    """
    This method sorts a given list of numbers in ascending order, using the
    bubble sort algorithm.
    :param data: The list of numbers to sort.
    :return: The given list, sorted in ascending order.
    """
    
    n = len(data)
    swapped = True

    while swapped: # While "work is done" inside the loop;
        swapped = False

        for i in range(1, n):
            if data[i - 1] > data[i]: # If the elements are out of order, swap them.
                tmp = data[i - 1]
                data[i - 1] = data[i]
                data[i] = tmp
                swapped = True # Show something happened in the loop.

    return data
        
