package main

import (
	"regexp"
	"unicode"
)

var regexPattern, _ = regexp.Compile("[^a-zA-Z]+")

// IsIsogram receive a word and return true if word is a isogram and false if it is not
func IsIsogram(word string) bool {
	if word == "" {
		return true
	}

	var seen = map[rune]bool{}
	for _, r := range word {
		if unicode.IsLetter(r) == false {
			continue
		}
		lowerRune := unicode.ToLower(r)
		if seen[lowerRune] == true {
			return false
		}
		seen[lowerRune] = true
	}
	return true
}

func main() {}
