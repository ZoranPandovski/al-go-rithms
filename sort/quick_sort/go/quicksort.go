package quicksort

// QuickSort uses the Quick sort algorithm to sort an integer slice.
// The following code implements Lomuto partition scheme, based on
// wall shifting idea and median-of-three pivot selection algorithm
// for higher optimality. You can read more about that here:
// https://en.wikipedia.org/wiki/Quicksort#Lomuto_partition_scheme
// https://en.wikipedia.org/wiki/Quicksort#Choice_of_pivot
func QuickSort(slice []int) {
	quickSort(slice, 0, len(slice)-1)
}

func quickSort(slice []int, from, to int) {
	if from < to {
		mid := partition(slice, from, to)
		quickSort(slice, mid+1, to)
		quickSort(slice, from, mid-1)
	}
}

func getMedian(slice []int, left, right int) int {
	mid := left + (right-left)/2

	if slice[left] < slice[mid] {
		if slice[right] < slice[left] {
			return left
		} else if slice[right] < slice[mid] {
			return right
		}
		return mid
	}
	if slice[right] < slice[mid] {
		return mid
	} else if slice[right] < slice[left] {
		return right
	}
	return left
}

func partition(slice []int, from, to int) int {
	pivot := getMedian(slice, from, to)
	wall := to

	slice[pivot], slice[from] = slice[from], slice[pivot]

	for nowPos := to; nowPos > from; nowPos-- {
		if slice[from] < slice[nowPos] {
			slice[nowPos], slice[wall] = slice[wall], slice[nowPos]
			wall--
		}
	}
	slice[from], slice[wall] = slice[wall], slice[from]
	return wall
}
