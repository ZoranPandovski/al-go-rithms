def fast_exp(base, power):
	result = 1

	current = base

	while power > 0:
		if power % 2 == 1:
			result = result * current

		current = current * current

		power = power // 2

	return result