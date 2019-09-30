def binary_search(arr, item):
  low = 0
  high = len(arr)-1
  result = -1
  while (low <= high):
    mid = (low + high)//2
    if item == arr[mid]:
      result = mid
      high = mid - 1
    elif (item < arr[mid]):
      high = mid - 1
    else:
      low = mid + 1
  return result
