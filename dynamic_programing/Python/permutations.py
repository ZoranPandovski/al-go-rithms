def ListToString(List): 
	return ''.join(List) 

def permutations(ls, a, b): 
	if a == b: 
		print(ListToString(ls))
	else: 
		for i in range(a , b+1): 
			ls[a], ls[i] = ls[i], ls[a] 
			permutations(ls, a+1, b) 
			ls[a], ls[i] = ls[i], ls[a] 

the_word = input()
n = len(the_word) 
a = list(the_word) 
permutations(a, 0, n-1) 