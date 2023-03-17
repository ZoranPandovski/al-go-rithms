# Python3 program to concatenate two strings

# Function that concatenates strings a[0..n1-1]
# and b[0..n2-1] and stores the result in c[]
def concatenate(a, b, c, n1, n2):

	# Copy characters of A[] to C[]
	i = -1
	for i in range(n1):
		c[i] = a[i]

	# Copy characters of B[]
	for j in range(n2):
		c[i] = b[j]
		i += 1

# Driver Code
if __name__ == "__main__":
	a = "Hi This is geeksforgeeks. "
	n1 = len(a)

	b = "You are welcome here."
	n2 = len(b)

	a = list(a)
	b = list(b)

	# Concatenate a[] and b[] and
	# store result in c[]
	c = [0] * (n1 + n2 - 1)

	concatenate(a, b, c, n1, n2)

	for i in c:
		print(i, end = "")

# This code is contributed by
# Isaac