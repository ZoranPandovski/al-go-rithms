package bubblesort

// BubbleSort Optimized implementation of bubble sort
func BubbleSort(arr []int) {
	for i := range arr[:len(arr)] {
		flag := false
		for j := range arr[:len(arr)-i-1] {
			if arr[j] > arr[j+1] {
				flag = true
				temp := arr[j+1]
				arr[j+1] = arr[j]
				arr[j] = temp
			}
		}
		// No Swapping happened, array is sorted
		if !flag {
			return
		}
	}
}
