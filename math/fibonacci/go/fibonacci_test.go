package fibonacci

import (
	"testing"
)

var testCase = []struct {
	n	int32
	result	int32
}{
	{1, 1},
	{5, 8},
	{9, 55},
  	{19, 6765},
  	{13, 377},
}

func TestFib(t *testing.T) {
	for _, tt := range testCase {

		actual := Fib(tt.n)
		if tt.result != actual {
			t.Errorf("N: %d Result: %d Actual: %d\n",tt.n, tt.result, actual)
		}
	}
}
