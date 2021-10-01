def strand(arr):
    item, sub = 0, [arr.pop(0)]
    while item < len(arr):
        if arr[item] > sub[-1]:
            sub.append((arr.pop(item)))
        else:
            item += 1
    return sub

def merge(arr1, arr2):
    output = []
    while len(arr1) and len(arr2):
        if arr1[0] < arr2[0]:
            output.append(arr1.pop(0))
        else:
            output.append(arr2.pop(0))
    output +=arr1
    output +=arr2
    return output

def strand_sort(arr):
    output = strand(arr)
    while len(arr):
        output = merge(output, strand(arr))
    return output


if __name__ == '__main__':
    # arr = input('enter the arr: ').split(',')
    # print(arr)
    # print(strand_sort(arr))
    inputs = [9,2,0,4,1,8,2,3,7]
    print("Input List:")
    print(inputs)
    
    output = strand_sort(inputs)
    print("Output List:")
    print(output)