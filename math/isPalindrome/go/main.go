package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func palindrome(check string) bool {
	for i := 0; i < len(check)/2; i++ {
		if check[i] != check[len(check)-i-1] {
			return false
		}
	}
	return true
}

func main() {

	reader := bufio.NewReader(os.Stdin)
	fmt.Print("Enter text to check if palindrome: ")
	text, _ := reader.ReadString('\n')
	text = strings.TrimSpace(text)
	if palindrome(text) {
		fmt.Println(text + " is a palindrome!")
	} else {
		fmt.Println(text + " is not a palindrome.")
	}
}
