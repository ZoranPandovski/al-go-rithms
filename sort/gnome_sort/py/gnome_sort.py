from __future__ import print_function
def gnomeSort( arr, n):
    index = 0
    while index < n:
        if index == 0:
            index = index + 1
        if arr[index] >= arr[index - 1]:
            index = index + 1
        else:
            arr[index], arr[index-1] = arr[index-1], arr[index]
            index = index - 1
 
    return arr
 
# Driver Code
arr = [ 34, 2, 10, -9]
n = len(arr)
 
arr = gnomeSort(arr, n)
print("Sorted seqquence after applying Gnome Sort :", end=' ')
for i in arr:
    print(i, end=' ')
    