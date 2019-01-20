
def quickSort(arr):
    sort(arr,0,len(arr)-1) 

def sort(arr, low, high):
    if (low < high):
        p = partition(arr, low, high)
        sort(arr, low, p - 1)
        sort(arr, p + 1, high)

def partition(arr, low, high):
    pivot = arr[high]
    i = (low - 1) 
    for j in range(low,high):
        if (arr[j] <= pivot):
            i+= 1
            arr[i],arr[j] = arr[j],arr[i]
    arr[i+1],arr[high] = arr[high],arr[i+1]
    return i + 1