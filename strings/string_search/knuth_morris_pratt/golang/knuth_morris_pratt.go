/*
	Knuth Morris Prath String Search algorithm Implementation
	For an indepth research see https://www.wikiwand.com/en/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm#/
	Author: radicalrafi
*/

package kmp

//Table Building Algorithm

func preKMP(T *[]int, pat string) {

	var i = 0
	var j = -1
	(*T)[0] = -1
	length := len(pat) - 1

	for i < length {
		for j > -1 && pat[i] != pat[j] {
			j = (*T)[j]

		}
		i++
		j++

		if pat[i] == pat[j] {
			(*T)[i] = (*T)[j]

		} else {
			(*T)[i] = j
		}
	}

}

//search kmp
func Search(str, pat string) int {

	n := make([]int, len(pat))
	//preprocessing
	preKMP(&n, pat)

	m := 0 //the beginning of the current match in str
	i := 0 //the position of the current character in pat

	for {
		if m+i > len(str) {
			break
		}

		if pat[i] == str[m+i] {
			i++
			if i == len(pat) {
				//an occurence was found we return it
				return m
			}
		} else {
			if n[i] > -1 {
				m = m + i - n[i]
				i = n[i]

			} else {
				m = m + i + 1
				i = 0
			}

		}
	}
	return -1
}
