package kmp

import (
	"fmt"
	"testing"
)

func TestTable(t *testing.T) {

	w := "ABCDABD"
	T := make([]int, len(w))
	preKMP(&T, w)
	correct := []int{-1, 0, 0, 0, -1, 0, 2}
	if T[0] != -1 || T[1] != 0 || T[2] != 0 || T[3] != 0 || T[4] != -1 || T[5] != 0 || T[6] != 2 {
		t.Errorf("Failed to Build KMP Table want %v got %v", correct, T)
	}
}

func TestSearch(*testing.T) {
	//let's create  a map of string pattern to run tests
	cases := map[string]string{
		"abracadabra":           "cad",   //pos = 4
		"hollycow":              "lyc",   //pos = 3
		"daveisgreat":           "sgr",   //pos = 5
		"sigmundelizabethfreud": "undel", //pos=4
	}
	solutions := []int{4, 3, 5, 4}
	for str, pat := range cases {
		for _, i := range solutions {
			pos := Search(str, pat)
			if pos != i {
				fmt.Errorf("Search was incorrect got %d , want %d", pos, i)
			}

		}
		fmt.Println("Test Running ... 100%")
	}
}
