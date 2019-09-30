package fast_exponentiation

func FastPower(base,exponent int64) int64 {
	if exponent == 0 {
		return 1
	}

	if exponent == 1 {
		return base
	}

	if exponent % 2 == 0 {
		return FastPower(base*base, exponent/2)
	} else {
		return base * FastPower(base*base, (exponent-1)/2)
	}
}
