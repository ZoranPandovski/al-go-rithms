package main

import (
	"fmt"
)

// Receives the array and the higher number in it
// Only accept positive numbers > 1
// The 0 position is not used
func countSort(vet []int, max int)([]int){
	var i int
	//Creates an auxiliar array in the number of the higher element in vet
	var vetC = make([]int, max + 1)
	//The result vet of the algoritm
	var vetB = make([]int, len(vet))

	//Count the number of equals elements in array
	for i = 1; i < len(vet); i++{
		vetC[vet[i]]++
	}

	//Make the sum to get the position of the element in the return array
	for i = 1; i < max+1; i++{
		vetC[i] += vetC[i-1]
	}

	//Put the element in his final position in the return array
	//Decrement vetC for the case exist more equal numbers in array
	for i = 1; i < len(vet); i++{
		vetB[vetC[vet[i]]] = vet[i];
        vetC[vet[i]]--;
	}

	return vetB
}

func main(){
	//The 0 position is not used
	vet := []int{0, 8, 10, 3, 2, 1, 9, 3, 7}

	fmt.Println("Before: ", vet)

	vet2 := countSort(vet, 10)

	fmt.Println("After: ", vet2)

}