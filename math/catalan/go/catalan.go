package catalan

func catalan(n int) int {
	if n < 0 {
		return 0
	}

	if n == 1 {
		return 1
	}

	return (4*n - 2) / (n + 1) * catalan(n-1)
}
