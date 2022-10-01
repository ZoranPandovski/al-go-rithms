def oddEvenSort(lst, n):
    isSorted = 0
    while isSorted == 0:
        isSorted = 1
        for i in range(1, n-1, 2):
            if lst[i] > lst[i+1]:
                lst[i], lst[i+1] = lst[i+1], lst[i]
                isSorted = 0

        for i in range(0, n-1, 2):
            if lst[i] > lst[i+1]:
                lst[i], lst[i+1] = lst[i+1], lst[i]
                isSorted = 0
    return


lst = list(map(int, input('Enter a number list to be sorted: ').split()))
n = len(lst)

oddEvenSort(lst, n)
print(lst)
