//Translation of Python implementation. See README for details of what this is supposed to do.
package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

//Returns True if input string is a palindrome
func check_palindrome(str string) bool {
	//First, remove uppercase characters and whitespace
	str = strings.Join(strings.Fields(strings.ToLower(str)), "")

	//Create a second string that is the mirror image of the first
	rev := reverse(str)

	return str == rev
}

//Flip the order of the charaters in a string
func reverse(s string) string {
	characters := []rune(s)
	start, end := 0, len(s)-1
	for ; start < end; start, end = start+1, end-1 {
		characters[start], characters[end] = characters[end], characters[start]
	}
	return string(characters)
}

func main() {
	getline := bufio.NewReader(os.Stdin)
	fmt.Print("Enter text: ")
	input, _ := getline.ReadString('\n')
	is_p := check_palindrome(input)
	if is_p {
		fmt.Println("The string is a palindrome")
	} else {
		fmt.Println("The string is not an palindrome.")
	}
}
