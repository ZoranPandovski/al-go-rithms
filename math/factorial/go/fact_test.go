package factorial

import "testing"

var testCase = []struct {
	n int64
	result int64
}{
	{0, 1},
	{5, 120},
	{10, 3628800},
	{7, 5040},
}

func TestFactorial(t *testing.T) {
	for _, tt := range testCase {
		actual := Factorial(tt.n)
		if tt.result != actual {
			t.Errorf("N: %d Result: %d Actual: %d\n",tt.n, tt.result, actual)
		}
	}
}
