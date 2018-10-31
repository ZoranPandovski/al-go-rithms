package caesar

// Caesar accepts a string and an integer to shift by
// and returns a string with its letters shifted by the
// amount given.
func Caesar(input string, shift int) string {
	runes := []rune(input)
	for i := 0; i < len(runes); i++ {
		newCP := int(runes[i]) + shift
		switch {
		case runes[i] >= 65 && runes[i] <= 90:
			for newCP > 90 {
				newCP -= 26
			}
			runes[i] = rune(newCP)
		case runes[i] >= 97 && runes[i] <= 122:
			for newCP > 122 {
				newCP -= 26
			}
			runes[i] = rune(newCP)
		}
	}

	return string(runes)
}
