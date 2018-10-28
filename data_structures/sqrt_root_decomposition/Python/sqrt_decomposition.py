import math

block = [0]*100
arr = [0]*10000

def preprocess(seq, n):
	
	# Initializing block pointer and claculating block size
	ind = -1
	block_size = math.sqrt(n)

	# calculating the value of each block : 
	for i in range(n):
		
		arr[i]= seq[i]
		if i%block_size == 0:
			ind+=1

		block[ind] += arr[i]

	return block_size

def query(l,r):

	res=0

	# Traversing first block :
	while l<r and l%block_size!=0 and l!=0 :
		res+=arr[l]
		l+=1

	# Travering all middle blocks :
	while l+block_size <= r :
		res += block[l//block_size]
		l+=block_size

	# Travering the last block :
	while l<=r :
		res+=arr[l]
		l+=1

	return res

def update(ind, val):

	# Updating the value of each block and array :
	block_ind = ind//block_size
	block[block_ind] += val - arr[ind]
	arr[ind]=val


''' Test Program Starts Here '''

seq = [1, 5, 2, 4, 6, 1, 3, 5, 7, 10];
n=len(seq)

block_size = preprocess(seq, n)

print("Query(3,8) : ", query(3,8))
print("Query(1,6) : ", query(1,6))
print("Query(8,8) : ", query(8,8))