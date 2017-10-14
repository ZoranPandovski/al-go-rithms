#ifndef _EUCLIDS_GCD_
#define _EUCLIDS_GCD_

int euclids_gcd(int a, int b)
{
	if (a == 0)
		return b;

	return euclids_gcd(b % a, a);
}

#endif