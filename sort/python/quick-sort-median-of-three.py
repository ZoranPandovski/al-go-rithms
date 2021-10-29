"""
  Python Program
  Quick sort with median of three numbers
"""

def quickSort(L):
  quicksorthelp(L, 0, len(L))


def quicksorthelp(L, first, last):
  if first < last: 
    pivot_location = Partition(L, first, last)
    quicksorthelp(L, first, pivot_location)
    quicksorthelp(L, pivot_location + 1, last)


def medianOfThree(L, first, last):
  mid = (first+last-1)//2
  a = L[first]
  b = L[mid]
  c = L[last-1]
  if a <= b <= c:
    return b, mid
  if c <= b <= a:
    return b, mid
  if a <= c <= b:
    return c, last-1
  if b <= c <= a:
    return c, last-1
  return a, first

def Partition(L, first, last):
  pivot, pidx = medianOfThree(L, first, last)
  L[first], L[pidx] = L[pidx], L[first]
  i = first + 1
  
  for j in range(first+1, last, 1):
    if (L[j] < pivot):
      L[i], L[j] = L[j], L[i]  
      i += 1
  
  L[first], L[i-1] = L[i-1], L[first] 
  return i - 1

alist = [54,26,93,17,77,31,44,55,20]
print("Before: ", alist)
quickSort(alist)
print("After: ", alist)
