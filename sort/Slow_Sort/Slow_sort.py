def slowsort(A, i, j):
		# This procedure sorts the subarray A[i]...A[j]
		if i >= j:
			return
		m = (i+j)/2
		slowsort(A, i, m)
		slowsort(A, m+1, j)
		if A[m] > A[j]:
			A[m],A[j] = A[j],A[m]
		slowsort(A, i, j-1)
