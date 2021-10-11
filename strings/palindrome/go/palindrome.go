package palindrome

import "strings"

// IsPalindrome returns if a string is palindrome or not
// compares by converting string to lowercase
func IsPalindrome(str string) bool {
	str = strings.ToLower(str)
	for i := 0; i < len(str)/2; i++ {
		if str[i] != str[len(str)-i-1] {
			return false
		}
	}
	return true
}
