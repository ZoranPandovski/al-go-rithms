class Node:
	def __init__(self, data):
		self.data = data
		self.isEndOfString = False
		self.left = None
		self.eq = None
		self.right = None


def insert(root, word):
	if not root:
		root = Node(word[0])
	if word[0] < root.data:
		root.left = insert(root.left, word)
	elif word[0] > root.data:
		root.right = insert(root.right, word)
	else:
		if len(word) > 1:
			root.eq = insert(root.eq, word[1:])
		else:
			root.isEndOfString = True
	return root

def traverseTSTUtil(root, buffer, depth):
	if root:
		traverseTSTUtil(root.left, buffer, depth)
		buffer[depth] = root.data
		if root.isEndOfString:
			print("".join(buffer[:depth+1]))
		traverseTSTUtil(root.eq, buffer, depth+1)
		traverseTSTUtil(root.right, buffer, depth)

def traverseTST(root):
	buffer = [''] * 50
	traverseTSTUtil(root, buffer, 0)

def searchTST(root, word):
	if not root:
		return False
	if word[0] < root.data:
		return searchTST(root.left, word)
	elif word[0] > root.data:
		return searchTST(root.right, word)
	else:
		if len(word) > 1:
			return searchTST(root.eq, word[1:])
		else:
			return root.isEndOfString

root = Node('')
insert(root, "cat")
insert(root, "cats")
insert(root, "up")
insert(root, "bug")

print("Following is traversal of ternary search tree:")
traverseTST(root)

print("\nFollowing are search results for 'cats', 'bu', and 'up':")
print("Found" if searchTST(root, "cats") else "Not Found")
print("Found" if searchTST(root, "bu") else "Not Found")
print("Found" if searchTST(root, "up") else "Not Found")
# This code is contributed by Shivam Tiwari
