package quicksort

// QuickSort uses the Quick sort algorithm to sort an integer slice.
// The following code implements the Hoare partition scheme and was
// ported from the pseudocode, that can be found on
// https://en.wikipedia.org/wiki/Quicksort#Hoare_partition_scheme.
func QuickSort(slice []int) {
	quickSort(slice, 0, len(slice)-1)

}

func quickSort(slice []int, lo int, hi int) {
	if lo < hi {
		p := partition(slice, lo, hi)
		quickSort(slice, lo, p)
		quickSort(slice, p+1, hi)
	}
}

func partition(slice []int, lo int, hi int) int {
	pivot := slice[lo]
	i := lo - 1
	j := hi + 1
	for {
		for ok := true; ok; ok = (slice[i] < pivot) {
			i++
		}
		for ok := true; ok; ok = (slice[j] > pivot) {
			j--
		}
		if i >= j {
			return j
		}
		slice[i], slice[j] = slice[j], slice[i]
	}
}
