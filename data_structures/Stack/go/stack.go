package main

import (
	"fmt"
	"bufio"
	"os"
)

type Node struct {
	data interface{}
	next *Node
}

var lengthOfStack = 0
var top *Node

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	for true {
		fmt.Println("Select one of the following options:")
		fmt.Println("1. Push")
		fmt.Println("2. Pop")
		fmt.Println("3. Length of stack")
		fmt.Println("4. Exit")

		scanner.Scan()
		fmt.Println("")
		
		switch scanner.Text() {
			case "1":
				push(scanner)
		
			case "2":
				pop()

			case "3":
				fmt.Println("The length of the stack is:", lengthOfStack)
				fmt.Println("")	
			
			case "4":
				os.Exit(0)

			default:
				fmt.Println("Please, select a valid option.")
		}
	}
}

func push(scanner *bufio.Scanner) {
	fmt.Println("Type the number you want to push into the stack")
	scanner.Scan()
	fmt.Println("")	

	lengthOfStack += 1
	
	if(top == nil) {
		top = &Node{scanner.Text(), nil}
		return
	}

	newNode := &Node{scanner.Text(), top}
	top = newNode
}

func pop() {
	if(top == nil) {
		fmt.Println("Empty stack")
		fmt.Println("")		
		return
	}

	fmt.Println("Element to pop:", top.data)
	fmt.Println("")	

	top = top.next

	lengthOfStack -= 1
}