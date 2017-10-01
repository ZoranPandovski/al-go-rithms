package insertionsort

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

func TestBubbleSort(t *testing.T) {
	cases := [][]int{{2, 1, 2, 7, 88, 4, 3, 6}, {3, 1, -1, 2, -10, -11, 20, 12, 34, 55, -22}}

	for _, arr1 := range cases {
		arr2 := make([]int, len(arr1))
		copy(arr2, arr1)

		InsertionSort(arr1)
		sort.Ints(arr2)

		if !equal(arr1, arr2) {
			t.Errorf("InsertionSort did not sort correctly.")
		}
	}

}
