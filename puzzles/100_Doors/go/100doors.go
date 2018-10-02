package main

import (
	"fmt"
	"sort"
)

func main() {
	doors := make(map[int]bool)
	for door := 1; door < 101; door++ {
		for walk := 1; walk < 101; walk++ {
			if door%walk == 0 {
				doors[door] = !doors[door]
			}
		}
	}

	var ans []int
	for key, door := range doors {
		if door {
			ans = append(ans, key)
		}
	}

	sort.Ints(ans)
	fmt.Print("Doors opened in the end are: ")
	for _, a := range ans {
		fmt.Printf("%v ", a)
	}
	fmt.Println("")
}
