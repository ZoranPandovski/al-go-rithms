package mergesort

// MergeSort uses the merge sort algorithm to sort an integer slice.
func MergeSort(slice []int) {
	sortedSlice := mergeSort(slice)
	for i, val := range sortedSlice {
		slice[i] = val
	}
}

func mergeSort(slice []int) []int {
	if len(slice) <= 1 {
		return slice
	}
	m := len(slice) / 2
	left := mergeSort(slice[:m])
	right := mergeSort(slice[m:])
	return merge(left, right)
}

func merge(left, right []int) []int {
	slice := make([]int, len(left)+len(right))
	i, j := 0, 0
	for i < len(left) && j < len(right) {
		if left[i] <= right[j] {
			slice[i+j] = left[i]
			i++
		} else {
			slice[i+j] = right[j]
			j++
		}
	}
	for ; i < len(left); i++ {
		slice[i+j] = left[i]
	}
	for ; j < len(right); j++ {
		slice[i+j] = right[j]
	}
	return slice
}
