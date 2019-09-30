# optimized - shifts instead of swapping		
def insertion_sort(A):
	for i in range(1, len(A)):
		curNum = A[i]
		k = 0
		for j in range(i-1, -2, -1):
			k = j
			if A[j] > curNum:
				A[j+1] = A[j]
			else:
				break
		A[k+1] = curNum
	return A

if __name__=="__main__":
    L = [10,67,2,998,23,56,32,21,91,21,22]
    print(insertion_sort(L))
    
