from bisect import bisect_left

# Binary Search
def binarySearch(arr, key, start, end): 
    i = bisect_left(arr, key, lo=start, hi=end) 
    if i != len(arr) and arr[i] == key:
        return i # key was found at index i
    else: 
        return -1 # the key was not found

# Exponential Search
def exponentialSearch(arr, size, key):
    # the key is the first element in the array, return
    if arr[0] == key: 
        return 0

    # Compare the search key (key) with the value at the current
    # search index (i). If the element at the current index is
    # smaller than the search key, skip to the next search index
    # by doubling it.
    i = 1
    while i < size and arr[i] <= key: 
        i = i * 2

    # Call the binary search with the range found.
    return binarySearch(arr, key, i / 2, min(i + 1, size))
  
# Example Usage
arr = [2, 3, 7, 9, 10, 15, 19, 25] # The array to search
size = len(arr) # Size of the array
key = 9 # What to search for

index = exponentialSearch(arr, size, key)

if index == -1: 
    print "The key %d was not found." % (key)
else: 
    print "The key %d was found at index %d." % (key, index)
