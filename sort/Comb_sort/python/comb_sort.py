import math

def comb_sort(arr):
    gap = len(arr)
    shrink = 1.3
    is_sorted = False
    aux = arr
    while (is_sorted == False):
        gap = math.floor(gap / shrink)
        if gap > 1:
            is_sorted = False
        else:
            gap = 1
            is_sorted = True
        i = 0
        while (i + gap < len(aux)):
            if aux[i] > aux[i + gap]:
                aux[i], aux[i + gap] = aux[i + gap], aux[i]
                is_sorted = False
            i = i + 1
    return aux

def test():
    list1 = [23,2,7,1,89,20,78,13]
    print(list1)
    print(comb_sort(list1))
    assert (sorted(list1) == comb_sort(list1))

if __name__ == '__main__':
    test()
