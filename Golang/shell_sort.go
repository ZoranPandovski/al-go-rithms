// Shell Sort in Golang
package main

import (
    "fmt"
    "math/rand"
    "time"
)

func main() {

    slice := generateSlice(20)
    fmt.Println("\n--- Unsorted --- \n\n", slice)
    shellsort(slice)
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

func shellsort(items []int) {
    var (
        n = len(items)
        gaps = []int{1}
        k = 1

    )

    for {
        gap := element(2, k) + 1
        if gap > n-1 {
            break
        }
        gaps = append([]int{gap}, gaps...)
        k++
    }

    for _, gap := range gaps {
        for i := gap; i < n; i += gap {
            j := i
            for j > 0 {
                if items[j-gap] > items[j] {
                    items[j-gap], items[j] = items[j], items[j-gap]
                }
                j = j - gap
            }
        }
    }
}

func element(a, b int) int {
    e := 1
    for b > 0 {
        if b&1 != 0 {
            e *= a
        }
        b >>= 1
        a *= a
    }
    return e
}
