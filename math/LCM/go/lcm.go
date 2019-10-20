package lcm

func __gcd(a, b int) int {
	if b == 0 {
		return a
	}

	return __gcd(b, a%b)
}

func lcm(a, b int) int {
	return a * b / __gcd(a, b)
}
