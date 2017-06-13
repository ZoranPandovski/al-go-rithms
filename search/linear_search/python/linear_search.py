# Return positon if given number is found in the list
def linear_search(list, key):
	for i, num in enumerate(list):
		if num == key:
			return i
	return None

# Return True if given number is found in the list
def linear_search1(list, key):
	position = 0
	found = False
	while position < len(list) and not found:		
		if list[position] == key:
			found = True
		position += 1
	return found

def test():
	position = linear_search([5,55,21,32,5,6,7,9999],7)
	found = linear_search1([5,55,21,32,5,6,7,9999],7)
	assert position == 6
	assert found == True

if __name__ == '__main__':
	test()
