package main
import (
	"fmt"
)

func main() {
	ch := factorial(4)
	for n := range ch {
		fmt.Println(n)
	}
}

func factorial(n int) chan int {
	out := make(chan int)
	go func() {
		sum := 1
		for i := n; i > 0; i-- {
			sum *= i
		}
		out <- sum
		close(out)
	}()
	return out
}
