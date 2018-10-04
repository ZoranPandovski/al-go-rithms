package bubblesort

// BubbleSort uses the bubble sort algorithm to sort an integer slice.
func BubbleSort(arr []int) {
	sorted := false
	for !sorted {
		sorted = true
		for i := range arr[:len(arr)-1] {
			if arr[i] > arr[i+1] {
				arr[i], arr[i+1] = arr[i+1], arr[i]
				sorted = false
			}
		}
	}
}
