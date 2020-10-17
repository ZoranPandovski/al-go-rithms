package fibonaccisearch

import "testing"

func TestFibonacciSearch(t *testing.T) {
	arr := []int{10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100}
	x := 100
	index := fibonnaciSearch(arr, x)
	expectedIndex := 10
	if index != expectedIndex {
		t.Errorf("Fibonnaci Search did not find an existing element in the slice at correct index, foundIndex: %d, expectedIndex: %d", index, expectedIndex)
	}
}
