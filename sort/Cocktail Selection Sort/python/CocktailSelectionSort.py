def cocktailSort(A):
    # make a range of all elements in array
    up = range(len(A) - 1)
    while True:
        # do looping for every element in the array
        # and then reverse the array and do the looping again
        for indices in (up, reversed(up)):
            # swapped variable to check if the array has been sorted or not
            swapped = False
            for i in indices:
                # compare an element to it's immediate next
                if A[i] > A[i + 1]:
                    # if the next element is smaller, swap them
                    (A[i], A[i + 1]) = (A[i + 1], A[i])
                    # check if there is a swapping operation in the current iteration
                    swapped = True
            # when there is no swapping it means the array is already sorted
            if not swapped:
                return

test1 = [7, 6, 5,  9,  8,  4,  3,  1,  2,  0]
cocktailSort(test1)
print(test1)
# >>> [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

test2 = list('big fjords vex quick waltz nymph')
cocktailSort(test2)
print(''.join(test2))
# >>>      abcdefghiijklmnopqrstuvwxyz
