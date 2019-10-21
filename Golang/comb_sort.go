// Comb Sort in Golang
package main

import (
    "fmt"
    "math/rand"
    "time"
)

func main() {

    slice := generateSlice(20)
    fmt.Println("\n--- Unsorted --- \n\n", slice)
    combsort(slice)
    fmt.Println("\n--- Sorted ---\n\n", slice, "\n")
}

// Generates a slice of size, size filled with random numbers
func generateSlice(size int) []int {

    slice := make([]int, size, size)
    rand.Seed(time.Now().UnixNano())
    for i := 0; i < size; i++ {
        slice[i] = rand.Intn(999) - rand.Intn(999)
    }
    return slice
}

func combsort(items []int) {
    var (
        n = len(items)
        gap = len(items)
        shrink = 1.3
        swapped = true
    )

    for swapped {
        swapped = false
            gap = int(float64(gap) / shrink)
            if gap < 1 {
            gap = 1
        }
        for i := 0; i+gap < n; i++ {
            if items[i] > items[i+gap] {
                items[i+gap], items[i] = items[i], items[i+gap]
                swapped = true
            }
        }
    }
}
