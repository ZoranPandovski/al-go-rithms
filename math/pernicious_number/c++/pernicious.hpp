#ifndef __PERNICIOUS_HPP__
#define __PERNICIOUS_HPP__

bool is_prime(int n)
{
	if (n < 2)
		return false;

	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;

	return true;
}

bool is_pernicious(long long int n)
{
	int bits = __builtin_popcount(n);

	return is_prime(bits);
}

#endif