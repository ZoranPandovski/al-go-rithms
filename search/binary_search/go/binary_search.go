package binarysearch

// BinarySearch performs a binary search on a given sorted integer slice
// 'sortedSlice' for an integer value 'value'. If this value can be found
// in the sorted slice, the index of the first occurence will be returned,
// together with a boolean 'true' to indicate, that the search was successful.
// If the given value is not contained in the slice, an arbitrary index can
// be returned, together with a boolean 'false' to indicate, that the
// given value is not contained in the slice.
func BinarySearch(value int, sortedSlice []int) (index int, found bool) {
	low, high := 0, len(sortedSlice)-1
	for low <= high {
		mid := (low + high) / 2
		if sortedSlice[mid] < value {
			low = mid + 1
		} else if sortedSlice[mid] > value {
			high = mid - 1
		} else if low != mid {
			high = mid
		} else {
			return mid, true
		}
	}
	return -1, false
}
