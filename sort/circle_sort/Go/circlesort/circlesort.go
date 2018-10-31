package circlesort

import (
	"fmt"
	"strings"
	"errors"
)

func CircleSort(arr []int) (string, error) {
	var sortedArr string
	if len(arr) > 0 {
		for ok := true; ok; ok = circleSortRec(arr, 0, len(arr) - 1) {
			sortedArr = strings.Trim(strings.Join(strings.Fields(fmt.Sprint(arr)), " "), "[]")
		}
		return sortedArr, nil
	}
	return "", errors.New("invalid array size")
}

func circleSortRec(arr []int,lo, hi int) bool {
	swapped := false

	if lo == hi {
		return false
	}

	high := hi
	low := lo
	mid := (hi - lo) / 2

	for lo < hi {
		if arr[lo] > arr[hi] {
			swap(arr, lo, hi)
			swapped = true
		}
		lo++
		hi--
	}

	// special case arises with odd size lists
	if lo == hi && arr[lo] > arr[hi + 1] {
		swap(arr, lo, hi + 1)
		swapped = true
	}

	firstHalf := circleSortRec(arr, low, low + mid)
	secondHalf := circleSortRec(arr, low + mid + 1, high)

	return swapped || firstHalf || secondHalf
}

func swap(arr []int, idx1, idx2 int) {
	tmp := arr[idx1]
	arr[idx1] = arr[idx2]
	arr[idx2] = tmp
}
