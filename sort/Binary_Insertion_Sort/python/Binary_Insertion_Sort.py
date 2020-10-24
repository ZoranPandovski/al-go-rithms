from __future__ import print_function
#Binary Insertion Sort using python

#using binary search to look for location to insert current value
#low is set as the lowest value in array and high is the highest value
#in sorted array
def BS(arr, val, low, high):

    #return the location of the smallest sorted value
    #that is greater than the current value to be inserted
    if low == high:
        if arr[low] > val:
            return low
        else:
            return low + 1

    if low > high:
        return low

    mid = (low + high) / 2

    #run binary search in the second half of sorted array
    #when the value to be inserted is greater than the average
    #of highest and lowest value in sorted array
    if arr[mid] < val:
        return BS(arr, val, mid+1, high)

    #run binary search in the first half of sorted array
    #when the value to be inserted is smaller than the average
    #of highest and lowest value in sorted array
    elif arr[mid] > val:
        return BS(arr, val, low, mid-1)

    #return the location of the center when the value to be inserted
    #and the average of highest and lowest value in sorted array
    #is equal
    else:
        return mid

def BIS(arr):
    #run binary search in every element in array
    #and immediately sort the array
    for i in range(1, len(arr)):
        val = arr[i]
        j = BS(arr, val, 0, i-1)
        arr = arr[:j] + [val] + arr[j:i] + arr[i+1:]
    return arr

print ("Sorted array: ")
print(BIS([37, 23, 0, 17, 45, 9, 80, 9, 9]))
