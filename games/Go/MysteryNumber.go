package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"strconv"
	"strings"
	"time"
)

const (
	maxRange string = "Enter the maximum value for the game :"
	errorInt string = "Integer required try agin"
	start    string = "Max value set"
	getValue string = "What is the number?"
	higer    string = "It's more"
	less     string = "It's less"
)

var (
	generatedValue int
	turn           = 0
)

// Read input from Stdin while input is not a Numeric
func readInput(output string) (num int) {
	for {
		// Create a new reader
		buf := bufio.NewReader(os.Stdin)
		fmt.Print(output + "\n")
		sentence, err := buf.ReadString('\n')
		// Check if error
		if err != nil {
			fmt.Println(err)
		} else {
			// remove newLine Char
			sentence = strings.TrimSuffix(sentence, "\n")
			// Check if input is numeric
			if result, converted := isNumeric(sentence); result {
				return converted
			}
			fmt.Println(string(errorInt))
		}
	}
}

// Check if a String is Numeric
func isNumeric(s string) (bool, int) {
	converted, err := strconv.ParseFloat(s, 64)
	return err == nil, int(converted)
}

// Game function
func game() {
	for {
		value := readInput(getValue)
		turn++
		if value > generatedValue {
			println(less)
		} else if value < generatedValue {
			println(higer)
		} else {
			fmt.Printf("Well played, you got it in %d turn !\n", turn)
			return
		}
	}
}

// Main function
func main() {
	max := readInput(maxRange)
	// Set seed otherwise rand.Intn will be the same value everytime
	rand.Seed(time.Now().UnixNano())
	generatedValue = rand.Intn(max)
	fmt.Println(start)
	game()
}
