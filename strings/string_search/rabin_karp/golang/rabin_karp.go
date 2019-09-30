/*
   Rabin Karp implementation

   Author:radicalrafi
*/

package rabinkarp

import (
	"math"
)

const base = 101

func rabinFingerprint(substr string) int64 {

	l := len(substr) - 1
	var hash int64
	for i := range substr {

		hash += int64(substr[i]) * int64(math.Pow(base, float64(l)))
		l--
	}
	return hash

}

//Single Rabin Karp Pattern Search
func Search(str string, pat string) int {

	n := len(str)
	m := len(pat)

	hashdPat := rabinFingerprint(pat)

	for i := 0; i < n-m+1; i++ {

		hs := rabinFingerprint(str[i : i+m])
		if hs == hashdPat {
			if str[i:i+m] == pat {
				return i
			}
		}
	}
	return -1
}
