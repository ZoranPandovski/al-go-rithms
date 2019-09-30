package euclidsGcd

import "testing"

var answers [][]int = [][]int{
	[]int{1, 10, 1},
	[]int{2, 4, 2},
	[]int{2, 9, 1},
	[]int{37, 91, 1},
	[]int{5, 10, 5},
	[]int{12210, 8352, 6},
}

func TestEuclidsGcd(t *testing.T) {
	for _, test := range answers {
		if EuclidsGcd(test[0], test[1]) != test[2] {
			t.Fail()
		}
	}
}
