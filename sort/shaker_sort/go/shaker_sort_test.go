package shakersort

import (
	"sort"
	"testing"
)

func TestSort(t *testing.T) {
	dataset := []float32{2, 7, 3, 9, 2, 5, 4, 1, 92, 12, 45, 22, 56, 24, 6.2}
	sorted := ShakerSort(dataset)
	sortedAscending := func(i, j int) bool {
		return sorted[i] < sorted[j]
	}
	isCorrectlySorted := sort.SliceIsSorted(sorted, sortedAscending)
	if isCorrectlySorted == false {
		t.Errorf("Failed to sort in ascending order using shaker sort algorithm.")
	}
}
