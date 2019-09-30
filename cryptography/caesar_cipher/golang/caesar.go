package main

import "strings"

// Caesar cipher
func Caesar(text string, s int) string {
	coded := make([]byte, 0, len(text))
	for i := range strings.ToLower(text) {
		coded = append(coded, shift(text[i], s))
	}
	return string(coded)
}

func shift(r byte, shift int) byte {
	if r == ' ' {
		return ' '
	}
	c := int(r) + shift
	if c > 'z' {
		return byte(c - 26)
	}
	if c < 'a' {
		return byte(c + 26)
	}
	return byte(c)
}
