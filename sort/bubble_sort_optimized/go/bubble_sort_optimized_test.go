package bubblesort

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
	arr1 := []int{2, 1, 2, 7, 88, 4, 3, 6}
	arr2 := make([]int, len(arr1))
	copy(arr2, arr1)

	BubbleSort(arr1)
	sort.Ints(arr2)

	if !equal(arr1, arr2) {
		t.Errorf("BubbleSort did not sort correctly.")
	}

}
