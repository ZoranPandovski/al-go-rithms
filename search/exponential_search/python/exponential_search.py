def binary_search(arr, low, high, x):
    while low <= high:
        mid = low + (high - low)/2;

        if arr[mid] == x:
            return mid
        elif arr[mid] < x:
            low = mid + 1
        else:
            high = mid - 1

    return -1

def exponential_search(arr, low, high, x):
    if arr[low] == x:
        return low

    i = (low + 1) * 2
    while i <= high and arr[i] <= x:
        i *= 2

    return binary_search(arr, i / 2, min(i, high), x)

arr = range(0,500)
x = 42
print(exponential_search(arr, 0, len(arr), x))
