"""
Input:
7/5+13/5

output:
4/1

"""

import re

def gcd(a, b):
	if (a == 0):
		return b;
	return gcd(b % a, a);


def lowest(den3, num3):

	common_factor = gcd(num3, den3);

	
	den3 = int(den3 / common_factor);
	num3 = int(num3 / common_factor);
	print(num3, "/", den3,sep="");


def addFraction(num1, den1, num2, den2):

	den3 = gcd(den1, den2);
	den3 = (den1 * den2) / den3;

	num3 = ((num1) * (den3 / den1) +
			(num2) * (den3 / den2));

	lowest(den3, num3);


print("write expression:")
exp=input()
array1 = re.findall(r'[0-9]+', exp)
array=list(map(int, array1))
addFraction(array[0], array[1], array[2], array[3]);
