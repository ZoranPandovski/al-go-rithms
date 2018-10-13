def bubble_sort_recursively(arr, i=0, j=0):
    if i >= len(arr) - 1:
        return
    if j < len(arr) - i - 1:
        if arr[j] > arr[j + 1]:
            arr[j], arr[j + 1] = arr[j + 1], arr[j]
        bubble_sort_recursively(arr, i, j + 1)
    else:
        bubble_sort_recursively(arr, i + 1, 0)


if __name__ == '__main__':
    arr = [5, 8, 2, 9, 3, 7, 1, 4, 6]
    bubble_sort_recursively(arr)
    print(arr)
