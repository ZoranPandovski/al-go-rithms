package binarysearch

import "testing"

func naiveSearch(value int, sortedSlice []int) (index int, found bool) {
	for i, val := range sortedSlice {
		if val == value {
			return i, true
		}
	}
	return -1, false
}

func TestHeapSort(t *testing.T) {
	testCases := []struct {
		value       int
		sortedSlice []int
	}{
		{4, []int{1, 3, 4, 5, 8, 9, 10}},
		{3, []int{1, 2, 5, 8, 10, 15, 20}},
		{8, []int{-2, 0, 4, 5, 8, 12, 14, 20, 34, 55, 60, 84, 111, 134, 154, 188, 189, 200}},
		{-1, []int{2, 4, 5, 8, 11, 23, 44}},
		{4, []int{1, 2, 2, 3, 4, 4, 4, 5, 6, 22}},
		{4, []int{2, 3, 4, 4, 5}},
		{1, []int{1, 2, 3, 4}},
		{4, []int{1, 2, 3, 4}},
		{1, []int{1, 2, 3, 4, 5}},
		{5, []int{1, 2, 3, 4, 5}},
		{2, []int{2, 2, 2, 2, 2, 2}},
	}

	for _, testCase := range testCases {
		expectedIndex, expectedFound := naiveSearch(testCase.value, testCase.sortedSlice)
		index, found := BinarySearch(testCase.value, testCase.sortedSlice)
		if expectedFound {
			if !found {
				t.Errorf("BinarySearch did not find an existing element in the slice.")
			} else if expectedIndex != index {
				t.Errorf("BinarySearch found element %v at index %v, expected %v", testCase.value, index, expectedIndex)
			}
		} else {
			if found {
				t.Errorf("BinarySearch found non-existing element %v at index %v", testCase.value, index)
			}
		}
	}
}
