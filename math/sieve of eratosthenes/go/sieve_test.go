package sieve

import (
	"testing"
)

var testCase = []struct {
	n      int
	result []int
}{
	{1, []int{}},
	{2, []int{2}},
	{5, []int{2, 3, 5}},
	{100, []int{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}},
	{500, []int{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499}},
}

func equalsArray(result, actual []int) bool {

	for i := 0; i < len(result); i++ {
		if result[i] != actual[i] {
			return true
		}
	}
	return false
}

func TestSieve(t *testing.T) {
	for _, tt := range testCase {

		actual := sieveOfEratosthenes(tt.n)
		if len(actual) != len(tt.result) {
			t.Errorf("N: %d Result: %d Actual: %d\n", tt.n, tt.result, actual)
			continue
		}

		if equalsArray(tt.result, actual) == true {
			t.Errorf("N: %d Result: %d Actual: %d\n", tt.n, tt.result, actual)
		}
	}
}
