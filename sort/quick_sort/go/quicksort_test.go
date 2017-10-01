package quicksort

import (
	"sort"
	"testing"
)

func equal(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}

func TestHeapSort(t *testing.T) {
	testCases := [][]int{
		{2, 1, 2, 7, 88, 4, 3, 6},
		{-2, 1, -2, -40, 10, 11, 48, -44, 0, 21, -121, 5066},
		{23, 12, 11, -20, 3, 1, -20, 3, 8, 9},
		{8, 7, 5, 4, 3, 2, 1},
		{1},
	}
	for _, arr1 := range testCases {
		arr2 := make([]int, len(arr1))
		copy(arr2, arr1)

		QuickSort(arr1)
		sort.Ints(arr2)

		if !equal(arr1, arr2) {
			t.Errorf("QuickSort did not sort correctly.")
		}
	}

}
