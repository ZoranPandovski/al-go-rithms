def bubbleSort(lst):
    for num in range(len(lst)-1,0,-1):
        for i in range(num):
            if lst[i]>lst[i+1]:
                temp = lst[i]
                lst[i] = lst[i+1]
                lst[i+1] = temp

lst = [1,4,26,3,77,99,32,43,51]
bubbleSort(lst)
print(lst)
