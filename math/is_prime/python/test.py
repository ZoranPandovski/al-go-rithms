from prime import is_prime

if __name__ == "__main__":

	for i in range(11):
		if is_prime(i):
			print ("{} is prime".format(i))
		else:
			print ("{} is not prime".format(i))