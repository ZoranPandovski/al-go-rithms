package fast_exponentiation

import (
	"testing"
	"math"
)

var testCase = []struct {
	base int64
	exponent int64
}{
	{10, 1},
	{10, 0},
	{10, 2},
	{3, 11},
	{2, 10},
	{2, 10},
	{20, 3},
	{31, 3},
	{4, 20},
}

func TestFastExponentiation(t *testing.T) {
	for _, tt := range testCase {
		result := float64(FastPower(tt.base, tt.exponent))
		expected := math.Pow(float64(tt.base), float64(tt.exponent))
		if expected != result {
			t.Errorf("Failed: %d^%d Result: %d Actual: %d\n", tt.base, tt.exponent, result, expected)
		}
	}
}
