package insertionsort

// InsertionSort sorts an integer slice by using the insertion sort algorithm.
func InsertionSort(arr []int) {
	for i := 1; i < len(arr); i++ {
		val := arr[i]
		j := i
		for j > 0 && arr[j-1] > val {
			arr[j] = arr[j-1]
			j--
		}
		arr[j] = val
	}
}
