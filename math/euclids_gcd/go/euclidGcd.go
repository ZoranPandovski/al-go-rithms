package euclidsGcd

func EuclidsGcd(a, b int) int {
	if a == 0 {
		return b
	}

	return EuclidsGcd(b%a, a)
}
