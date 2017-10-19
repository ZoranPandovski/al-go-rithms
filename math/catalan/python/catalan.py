def catalan (n):
	if n <= 1:
		return 1

	num = 1
	for i in range(n + 1, 2 * n + 1):
		num *= i

	den = 1
	for i in range(1, n + 1):
		den *= i

	res = (num / den) / (n + 1)

	return res