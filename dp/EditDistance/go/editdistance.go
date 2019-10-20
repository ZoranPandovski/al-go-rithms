// editdistance.go
package main

import (
	"fmt"
)

func editdistance(n string, m string, ln1 int, ln2 int) int {

	if ln1 <= 0 {
		return 0
	}
	if ln2 <= 0 {
		return ln1
	}

	//last chars are the same. Start next recursion
	if n[ln1-1] == m[ln2-1] {
		return editdistance(n, m, ln1-1, ln1-1)
	}

	//last chars are not the same: calculate recursivly the minimum of insert, delete and replace operations
	return (1 + min(
		editdistance(n, m, ln1, ln2-1),    //insert
		editdistance(n, m, ln1-1, ln2),    //delete
		editdistance(n, m, ln1-1, ln2-1))) //replace

}

func min(x int, y int, z int) int {
	if x <= y && x <= z {
		return x
	}
	if y <= x && y <= z {
		return y
	}
	return z
}

func main() {
	n := "kitten"
	m := "kitt"
	fmt.Println(editdistance(n, m, len(n), len(m)))
}
