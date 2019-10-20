# Author: thisHermit

ASCENDING = 1
DESCENDING = 0


N = 5
def main():
    
    input_array = [5, 4, 3, 2, 5]
    a = input_array.copy()
    
    # sort the array 
    sort(a, N)

    # test and show
    assert a, sorted(input_array)
    show(a, N)
 
def exchange(i, j, a, n):
    a[i], a[j] = a[j], a[i]


def compare(i, j, dirr, a, n):
    if dirr == (a[i] > a[j]):
        exchange(i, j, a, n)

def bitonicMerge(lo, cnt, dirr, a, n):
    if cnt > 1:

        k = cnt // 2
        for i in range(lo, lo + k):
            compare(i, i+k, dirr, a, n)
        bitonicMerge(lo, k, dirr, a, n)
        bitonicMerge(lo + k, k, dirr, a, n)


def bitonicSort(lo, cnt, dirr, a, n):
    if cnt > 1:
        k = cnt // 2

        # sort in ascending order
        bitonicSort(lo, k, ASCENDING, a, n)

        # sort in descending order
        bitonicSort(lo + k, k, DESCENDING, a, n)

        # Merge whole sequence in ascendin/ descending order depending on dirr
        bitonicMerge(lo, cnt, dirr, a, n)

def sort(a, n):
    bitonicSort(0, N, ASCENDING, a, n)


def show(a, n):
    print(a)

if __name__ == '__main__':
    main()
