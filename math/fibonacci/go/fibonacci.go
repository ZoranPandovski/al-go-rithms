package fibonacci

func Fib(n int32) int32 {
	var fibonacci [100]int32
	fibonacci[0], fibonacci[1] = 1, 1

	i := 2

	for ; i <= n; i++ {
		fibonacci[i] = fibonacci[i-1] + fibonacci[i-2]
	}

	return fibonacci[i-1]
}
