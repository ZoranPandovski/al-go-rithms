package main

import "testing"

func TestLinearSearch(t *testing.T) {
	testTable := []struct {
		Input  []int
		Find   int
		Output int
		Error  error
	}{
		{[]int{3, 2, 1, 5}, 2, 1, nil},
		{[]int{3, 2, 1, 5}, 42, 0, ErrNotFound},
	}

	for _, tt := range testTable {
		idx, err := LinearSearch(tt.Input, tt.Find)
		if idx != tt.Output {
			t.Errorf("Output missmatch! Expected: %d, Got: %d", tt.Output, idx)
		}

		if err != tt.Error {
			t.Errorf("Error missmatch! Expected: %v, Got: %v", tt.Error, err)
		}
	}
}
