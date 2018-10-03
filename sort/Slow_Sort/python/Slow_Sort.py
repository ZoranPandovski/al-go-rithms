def slowsort(A, i, j):
    (i, j) = (int(i), int(j))
    if i >= j:
        return
    m = (i + j) / 2
    m = int(m)
    slowsort(A, i, m)
    slowsort(A, m + 1, j)
    if A[m] > A[j]:
        A[m], A[j] = A[j], A[m]
    slowsort(A, i, j - 1)

test = [7, 6, 5, 9, 8, 4, 3, 1, 2, 0]
slowsort(test, 0, len(test) - 1)
print(test)
# >>> [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
			