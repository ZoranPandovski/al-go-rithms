package main

import (
	"fmt"
	"math"
)

func getWater(array_bar []int) int {

	left := 0
	right := len(array_bar) - 1
	println(right)
	left_max := 0
	right_max := 0
	water_trapped := 0

	for left < right {
		left_max = int(math.Max(float64(left_max), float64(array_bar[left])))
		right_max = int(math.Max(float64(right_max), float64(array_bar[right])))

		if left_max <= right_max {
			water_trapped += left_max - array_bar[left]
			left += 1

		} else {
			water_trapped += right_max - array_bar[right]
			right -= 1

		}

	}
	return water_trapped

}

func main() {

	var number_of_bars int
	var bar_array []int
	var water_int int

	fmt.Println("\nEnter the number of bars:")
	fmt.Scan(&number_of_bars)
	for i := 0; i < number_of_bars; i++ {
		fmt.Printf("Bar %d height =", i+1)
		fmt.Scan(&water_int)
		bar_array = append(bar_array, water_int)
	}
	max_water := getWater(bar_array)

	fmt.Printf("\nThe maximum water that be trapped is : %d", max_water)
}
