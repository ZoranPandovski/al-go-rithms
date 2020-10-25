package palindrome

import "testing"

func TestPalindrome(t *testing.T) {
	testCases := []struct {
		str    string
		result bool
	}{
		{"Madam", true},
		{"string", false},
		{"bananab", true},
	}

	for _, testcase := range testCases {
		res := IsPalindrome(testcase.str)
		if res != testcase.result {
			t.Errorf("Wrong Result for string: %v. Expected: %v , Got: %v", testcase.str, testcase.result, res)
		}
	}
}
