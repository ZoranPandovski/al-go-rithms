#1 /usr/bin/python

from catalan import catalan

if __name__ == "__main__":

	for i in range(10):
		print("catalan({}) == {}".format(i, catalan(i)))