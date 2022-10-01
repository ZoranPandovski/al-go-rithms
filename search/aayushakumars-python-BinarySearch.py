def binarySearch(array,l,r,x):


  while l <=r:

    mid = l + (r-1)//2

    if array[mid] == x:
      return mid
    
    elif array[mid] > x:
      r = mid-1 
    
    else:
      l = mid +1

  return -1



array = [2,4,5,6,7,9,10,23,53]

item = 23

result = binarySearch(array, 0, len(array)-1, item)


if result != -1:
  print("number found at index",result)
else:
  print("number not found")
