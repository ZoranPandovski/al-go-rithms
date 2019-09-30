// editdistance_test.go
package main

import (
	"testing"
	_ "testing"
)

func Test(t *testing.T) {
	n := "sunday"
	m := "monday"
	cost := editdistance(n, m, len(n), len(m))
	if cost != 2 {
		t.Error("cost is not 2. Its: ", cost)
	}
}
