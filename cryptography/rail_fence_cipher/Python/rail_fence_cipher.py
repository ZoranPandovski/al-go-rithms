# used for decryption, take the second element for sorting
def takeSecond(elem):
    return elem[1]

def display_rail(lines):
	depth = len(lines)
	col = len(lines[0])
	# depth is the number of rows of the grid
	# lines is a tuple where line[i] is the i-th line to print
	# col is the number of columns = number of characters of the initial string
	for i in range(0,depth):
		print( ( ("| %c "*col) + "|") % tuple(lines[i]) )

def encrypt(string,depth):
	#make sure that string is a string!
	string = str(string)
	
	nChar = len(string)
	# create a nested list with 'depth' number of items
	# each item has a number of characters = length of the string to cypher
	# initialize the list with all spaces:
	lines = [ [' ',]*nChar for _ in range(depth)]
	
	encStrings = list()
	# encStrings will be a list dynamically filled with the letters of 'string'
	# each item of the list will represent a row of the rail.
	# this list will then have 'depth' items
	encrStrings = ['' for _ in range(depth)]
	
	# Define the sequence in which the rows are filled
	if depth == 2:
		row_sequence = [0,1]
	else:
		row_sequence = [i for i in range(0,depth)]
		row_sequence.extend(range(depth-2,0,-1) )
	
	# length of the sequence
	seqLen = len(row_sequence)
	
	for i in range(0,nChar):
		row = row_sequence[i%seqLen] #repeatedly go through the sequence
		lines[row][i] = string[i]
		encrStrings[row] = encrStrings[row] + string[i]
		
	display_rail(lines)
	encrString = ''.join(c for c in encrStrings)
	
	return encrString
	
def decrypt(encrString,depth):
	# from depth and the length of the string we can determin the sequence
	# of places in the rails as they were filled
	nChar = len(encrString)
	if depth == 2:
		row_sequence = [1,2]
	else:
		row_sequence = [i for i in range(0,depth)]
		row_sequence.extend(range(depth-2,0,-1) )
		
	# length of the sequence
	seqLen = len(row_sequence)
	
	sequence = []
	# build a list with the indexes of rows and column according to the sequence
	for i in range(0,nChar):
		row = row_sequence[i%seqLen] #repeatedly go through the sequence
		sequence.append([row,i])
		
	# sort according to rows (so in the order the encrypted string is taken)
	sequence.sort()
	
	# now associate the encrypted string to the rail 'coordinates'
	for i in range(nChar):
		sequence[i].append(encrString[i])
		
	# finally for decription we rearrange the list items according to columns and read the result
	sequence.sort(key=takeSecond)
	string = ''.join(c[2] for c in sequence)
	
	return string
	
	
# EXAMPLES
	
# check that len(string)>depth
print("encryptions with depth 2: ")
res = encrypt("rail fence",2)
print("rail fence: " + res)
res = decrypt(res,2)
print("decryption -> " + res)

res = encrypt("Github",2)
print("Github: " + res)
res = decrypt(res,2)
print("decryption -> " + res)

res = encrypt("I am a test!",2)
print("I am a test! -> " + res)
res = decrypt(res,2)
print("decryption -> " + res)

print("encryptions with depth 3: ")
res = encrypt("rail fence",3)
print("rail fence: " + res)
res = decrypt(res,3)
print("decryption -> " + res)

res = encrypt("Github",3)
print("Github: " + res)
res = decrypt(res,3)
print("decryption -> " + res)

res = encrypt("I am a test!",3)
print("I am a test! -> " + res)
res = decrypt(res,3)
print("decryption -> " + res)
