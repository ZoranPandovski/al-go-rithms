# Author: thisHermit


def stoogesort(array, l, h):
    if (l >= h):
        return

    # if first element is smaller than last,
    # swap them
    if (array[l] > array[h]):
        array[l], array[h] = array[h], array[l]

    # if there are more than 2 elements in
    # array
    if (h - l + 1 > 2):
        t = (h - l + 1) // 3;

        # recursively sort first 2/3 elements
        stoogesort(array, l, h - t)

        # recursively sort last 2/3 elements
        stoogesort(array, l + t, h)

        # recursively sort first 2/3 elements
        # again to confirm
        stoogesort(array, l, h - t)

def main():
    input_array = [2, 4, 5, 3, 1]
    sorted_array = input_array.copy()

    stoogesort(sorted_array, 0, len(input_array) - 1)

    assert (sorted(input_array) == sorted_array)


if __name__ == '__main__':
    main()
