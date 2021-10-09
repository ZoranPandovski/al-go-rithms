// An implementation of the pretty useless sleep sort. Much like bogosort, it's only really useful for educational
// purposes
package main

import (
	"time"
)

func main(){
	var num = []int{4,5,2,1,3}

	res := make(chan int)
	for x := 0; x < len(num); x++ {
		go func(n int){
			time.Sleep(time.Duration(n) * time.Second)
			res <- n
		}(num[x])
	}

	var sorted []int
	for x := 0; x < len(num); x++ {
		sorted = append(sorted, <-res)
	}
}
