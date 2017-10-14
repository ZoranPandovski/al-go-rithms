#!/usr/bin/python3

from fast_exponentiation import fast_exp

if __name__ == "__main__":
	print("2 ^ 4 = {}".format(fast_exp(2, 4)))

	print("10 ^ 100 = {}".format(fast_exp(10, 100)))

	print("123 ^ 123 = {}".format(fast_exp(123, 123)))