
def insertionSort(arr): 
	for i in range(1, len(arr)): 

		key = arr[i]  
		k = i-1
		while k >=0 and key < arr[k] : 
				arr[k+1] = arr[k] 
				k -= 1
		arr[k+1] = key 
arr = [12, 11, 13, 5, 6] 
insertionSort(arr) 
print ("Sorted array is:") 
for i in range(len(arr)): 
	print ("%d" %arr[i]) 

