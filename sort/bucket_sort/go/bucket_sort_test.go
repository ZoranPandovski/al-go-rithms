package main

import (
	"sort"
	"testing"
)

func TestBucketSort(t *testing.T) {
	t.Run("random array", func(t *testing.T) {
		arr := []int{2, 5, 1, 6, 3, 9, 0, 4}
		bucketSort(arr)

		if !sort.IntsAreSorted(arr) {
			t.Fail()
		}
	})

	t.Run("descending-sorted array", func(t *testing.T) {
		arr := []int{7, 6, 5, 4, 3, 2, 1, 0}
		bucketSort(arr)

		if !sort.IntsAreSorted(arr) {
			t.Fail()
		}
	})

	t.Run("sorted array", func(t *testing.T) {
		arr := []int{0, 1, 2, 3, 4, 5, 6, 7}
		bucketSort(arr)

		if !sort.IntsAreSorted(arr) {
			t.Fail()
		}
	})
}
