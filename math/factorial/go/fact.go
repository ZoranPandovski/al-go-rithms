package factorial

func Factorial(n int64) int64{
	if n > 1 {
		return n * Factorial(n-1)
	} else {
		return 1
	}
}
