package main

import "fmt"

func main() {
	var input int
	fmt.Print("Enter an integer number: ")
	fmt.Scan(&input)

	if input%2 == 0 {
		fmt.Println(input, "is an even number.")
	} else {
		fmt.Println(input, "is an odd number.")
	}
}
