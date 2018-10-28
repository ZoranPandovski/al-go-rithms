def circle_sort_backend(A, L, R):
    n = R - L
    if n < 2:
        return 0

    swaps = 0
    m = n // 2

    for i in range(m):
        if A[R - (i + 1)] < A[L + i]:
            A[R - (i + 1)], A[L + i] = A[L + i], A[R - (i + 1)]
            swaps += 1

    if n & 1 and A[L + m] < A[L + m - 1]:
        A[L + m - 1], A[L + m] = A[L + m], A[L + m - 1]
        swaps += 1

    return swaps + circle_sort_backend(A, L, L + m) + circle_sort_backend(A, L + m, R)

def circle_sort(L):
    ''''Sort L in place, returning the number of swaps'''

    swaps = 0
    s = 1
    while s:
        s = circle_sort_backend(L, 0, len(L))
        swaps += s

    return swaps

test = [7, 6, 5, 9, 8, 4, 3, 1, 2, 0]
print(circle_sort(test))
# 12
print(test)
# [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
