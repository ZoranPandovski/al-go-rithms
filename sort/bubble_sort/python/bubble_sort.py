def bubble_sort(arr):
	sorted = False
	while not sorted:
		sorted = True
		for i in range(len(arr) -1):
			if arr[i] > arr[i + 1]:
				sorted = False
				temp = arr[i]
				arr[i] = arr[i+1]
				arr[i+1] = temp
	return arr


def test():
	arr = [2, 1, 2, 7, 88, 4, 3, 6]
	sorted_arr = bubble_sort(arr)
	assert (sorted(arr) == sorted_arr) == True
	


test()
