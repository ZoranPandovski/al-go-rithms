#For more info
#http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-a/
#Python 3 implementation

def toString(List):
    return ''.join(List)

def permutations(a,l,r):
	if(l == r):
		print(toString(a))

	for i in range(l,r+1):

		#Swap characters
		a[l],a[i] = a[i],a[l]

		#Recursion
		permutations(a,l+1,r)

		#Backtracking
		a[l],a[i] = a[i],a[l]


string = list("abc")
permutations(string,0,len(string)-1,)