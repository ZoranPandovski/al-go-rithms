def interpolationSearch(arr, n, x):
    lo = 0
    hi = (n - 1)
    while lo <= hi and x >= arr[lo] and x <= arr[hi]:
        pos  = lo + int(((float(hi - lo) / ( arr[hi] - arr[lo])) * ( x - arr[lo])))
        if arr[pos] == x:
            return pos
        if arr[pos] < x:
            lo = pos + 1;
        else:
            hi = pos - 1;
    return -1
 


arr = [1, 3, 7, 12, 14, 19, 23, 26, 30, 34, 35, 39, 46, 53]
n = len(arr) 
x = 35 # Element to be searched
index = interpolationSearch(arr, n, x) 
if index != -1:
    print("Element found at index",index)
else:
    print("Element not found")
