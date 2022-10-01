package main

import (
	"fmt"
)

// takes the original string as a parameter
// returns its permutation(s), as a slice
func permutations(str string) []string {
	strAsRune := []rune(str)
	if len(str) == 1 {
		// return only the original string
		return []string{str}
	} else {
		var result []string
		for index := range str {
			// swap 1st character and character at index 'index'
			temp := strAsRune[0]
			strAsRune[0] = strAsRune[index]
			strAsRune[index] = temp

			// exclude the 1st character, and permute the rest of it
			permutationsExcludingFirstChar := permutations(string(strAsRune)[1:])

			// then, take each of those permutations append the 1st character to them
			// then append them into the resultant slice(which is to be returned)
			for _, eachPerm := range permutationsExcludingFirstChar {
				result = append(result, string(strAsRune[0])+eachPerm)
			}
		}
		return result
	}
}

func main() {
	input := ""
	fmt.Printf("Enter a word(without spaces): ")
	fmt.Scanln(&input)
	result := permutations(input)
	fmt.Println("number of permutation(s):", len(result))
	fmt.Println("permutation(s):", result)
}
