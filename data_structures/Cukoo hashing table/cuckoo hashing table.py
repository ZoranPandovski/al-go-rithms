# upper bound on number of elements in our set
MAXN = 11

# choices for position
ver = 2

# Auxiliary space bounded by a small multiple
# of MAXN, minimizing wastage
hashtable = [[float('inf')] * MAXN for _ in range(ver)]

# Array to store possible positions for a key
pos = [0] * ver

def init_table():
	"""function to fill hash table with dummy value
	dummy value: float('inf')
	number of hashtables: ver"""
	for i in range(ver):
		for j in range(MAXN):
			hashtable[i][j] = float('inf')

def hash(function, key):
	"""return hashed value for a key
	function: ID of hash function according to which key has to hashed
	key: item to be hashed"""
	if function == 1:
		return key % MAXN
	elif function == 2:
		return (key // MAXN) % MAXN

def place(key, table_id, cnt, n):
	"""function to place a key in one of its possible positions
	table_id: table in which key has to be placed, also equal to function
	according to which key must be hashed
	cnt: number of times function has already been called in order to place
	the first input key
	n: maximum number of times function can be recursively called before
	stopping and declaring presence of cycle"""
	# if function has been recursively called max number of times, stop
	# and declare cycle. Rehash.
	if cnt == n:
		print(f"{key} unpositioned")
		print("Cycle present. REHASH.")
		return

	# calculate and store possible positions for the key. check if key
	# already present at any of the positions. If YES, return.
	for i in range(ver):
		pos[i] = hash(i + 1, key)
		if hashtable[i][pos[i]] == key:
			return

	# check if another key is already present at the position for the
	# new key in the table
	# If YES: place the new key in its position and place the older key
	# in an alternate position for it in the next table
	if hashtable[table_id][pos[table_id]] != float('inf'):
		dis = hashtable[table_id][pos[table_id]]
		hashtable[table_id][pos[table_id]] = key
		place(dis, (table_id + 1) % ver, cnt + 1, n)
	else: # else: place the new key in its position
		hashtable[table_id][pos[table_id]] = key

def print_table():
	"""function to print hash table contents"""
	print("Final hash tables:")
	for i in range(ver):
		print()
		for j in range(MAXN):
			if hashtable[i][j] == float('inf'):
				print("- ", end="")
			else:
				print(f"{hashtable[i][j]} ", end="")
	print()

def cuckoo(keys, n):
	# initialize hash tables to a dummy value (float('inf'))
	# indicating empty position
	init_table()

	# start with placing every key at its position in the first
	# hash table according to first hash function
	for i in range(n):
		cnt = 0
		place(keys[i], 0, cnt, n)

	# print the final hash tables
	print_table()

# driver function
def main():
	# following array doesn't have any cycles and
	# hence all keys will be inserted without any
	# rehashing
	keys_1 = [20, 50, 53, 75, 100, 67, 105, 3, 36, 39]

	cuckoo(keys_1, len(keys_1))

	# following array has a cycle and hence we will
	# have to rehash to position every key
	keys_2 = [20, 50, 53, 75, 100, 67, 105, 3, 36, 39, 6]

	cuckoo(keys_2, len(keys_2))

if __name__ == "__main__":
	main()

# This code is contributed by Isaac Martin
