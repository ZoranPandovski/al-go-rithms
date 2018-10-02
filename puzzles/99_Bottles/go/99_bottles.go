package main

import "fmt"

const INITIAL_BOTTLES = 99

func sing(num int) {
	if num == 0 {
		fmt.Printf("%v bottles of beer on the wall, %v bottles of beer.\n", "No more", "no more")
		fmt.Printf("Go to the store and buy some more, %v bottles of beer on the wall.\n", INITIAL_BOTTLES)
	} else if num == 1 {
		fmt.Printf("%v bottles of beer on the wall, %v bottles of beer.\n", num, num)
		fmt.Printf("Take one down and pass it around, %v bottles of beer on the wall.\n", "no more")
	} else {
		fmt.Printf("%v bottles of beer on the wall, %v bottles of beer.\n", num, num)
		fmt.Printf("Take one down and pass it around, %v bottles of beer on the wall.\n", num-1)
	}
}

func main() {
	for num := INITIAL_BOTTLES; num >= 0; num-- {
		sing(num)
	}
}
