def prime_factorize(n):
	if (n == 1):
		return []
	prime = 2
	answer=[]
	m = n
	while (m > 1):
		pwr = 0
		while (m % prime == 0):
			m /= prime
			pwr = pwr + 1
		if (pwr > 0):
			temp=[prime, pwr]
			answer.append(temp)
		prime = prime + 1
	return answer

n = int(input())
print(prime_factorize(n))