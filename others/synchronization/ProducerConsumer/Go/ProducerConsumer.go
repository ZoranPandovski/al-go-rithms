// Producer-Consumer implementation in go
package main

import (
	"fmt"
)

var done = make(chan bool)
var msgs = make(chan int)

func producer() {
	for i := 0; i < 10; i++ {
		// assign i to msgs when msgs is null
		msgs <- i
	}
	done <- true
}

func consumer() {
	for {
		// msg takes the value from msgs when msgs isn't null
		msg := <-msgs
		fmt.Println(msg)
	}
}

func main() {
	go producer()
	go consumer()
	// execute when done isn't null
	<-done
}
