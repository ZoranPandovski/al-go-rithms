
parent=[]
size=[]

def initialize(n):
	for i in range(0,n+1):
		parent.append(i)
		size.append(1)

def find(x):
	if parent[x] == x:
		return x
	else:
		parent[x] = find(parent[x])
		return parent[x]


def join(a,b):
	p_a = find(a)
	p_b = find(b)

	if p_a != p_b:
		if size[p_a] < size[p_b]:
			parent[p_a] = p_b
			size[p_b] += size[p_a]
		else:
			parent[p_b] = p_a
			size[p_a] += size[p_b]


''' Main Program Starts Here '''

n=5
initialize(n)
join(1,2)
join(2,3)
join(4,5)

print(find(3))
		
