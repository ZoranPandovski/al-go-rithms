package circlesort_test

import (
	"testing"
	"circleSort/circlesort"
)

func TestValidCircleSort(t *testing.T) {
	arr := []int{1, 6, 2, 4, 9, 0, 5, 3, 7, 8}
	if _, err := circlesort.CircleSort(arr); err != nil {
		t.Fatal(err)
	}
}

func TestInvalidCircleSort(t *testing.T) {
	arr := make([]int, 0)
	if _, err := circlesort.CircleSort(arr); err == nil {
		t.Fatal(err)
	}
}