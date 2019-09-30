package rabinkarp

import "testing"
import "fmt"

func TestRabinFingerprint(t *testing.T) {

	cases := []struct {
		in   string
		want int64
	}{
		{"abr", 999509},
		{"bra", 1011309},
	}
	for _, c := range cases {

		got := rabinFingerprint(c.in)
		if got != c.want {
			t.Errorf("RabinFingerprint(%q) == %q,want %q", c.in, c.want)
		}
	}
}

func TestSingleRabinKarp(t *testing.T) {

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
