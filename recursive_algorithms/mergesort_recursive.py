def merge_sort(array):
    temp = []
    if( len(array) == 1):
        return array;
      
    half  = len(array) / 2
    lower = merge_sort(array[:half])
    upper = merge_sort(array[half:])
    lower_len = len(lower)
    upper_len = len(upper)
    i = 0
    j = 0
    while i != lower_len or j != upper_len:
        if( i != lower_len and (j == upper_len or lower[i] < upper[j])):
            temp.append(lower[i])
            i += 1
        else:
            temp.append(upper[j])
            j += 1

    return temp

  
array = [11, 12, 3, 28, 41, 62,16, 10]
ar = merge_sort(array)
print " ".join(str(x) for x in ar)
