def is_prime(n):
	if n < 2:
		return False

	i = 2

	while i * i <= n:
		if n % i == 0:
			return False

		i += 1

	return True