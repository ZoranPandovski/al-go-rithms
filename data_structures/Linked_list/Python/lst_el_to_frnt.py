# Python3 code to move the last item to front

class Node:
	def __init__(self, data):
		self.data = data
		self.next = None


class LinkedList:
	def __init__(self):
		self.head = None

	# Function to add a node
	# at the beginning of Linked List
	def push(self, data):
		new_node = Node(data)
		new_node.next = self.head
		self.head = new_node

	# Function to print nodes in a
	# given linked list
	def printList(self):
		tmp = self.head
		while tmp is not None:
			print(tmp.data, end=", ")
			tmp = tmp.next
		print()

	# Function to bring the last node to the front
	def moveToFront(self):
		tmp = self.head
		sec_last = None # To maintain the track of
		# the second last node

	# To check whether we have not received
	# the empty list or list with a single node
		if not tmp or not tmp.next:
			return

		# Iterate till the end to get
		# the last and second last node
		while tmp and tmp.next:
			sec_last = tmp
			tmp = tmp.next

		# point the next of the second
		# last node to None
		sec_last.next = None

		# Make the last node as the first Node
		tmp.next = self.head
		self.head = tmp


# Driver's Code
if __name__ == '__main__':
	llist = LinkedList()

	# swap the 2 nodes
	llist.push(5)
	llist.push(4)
	llist.push(3)
	llist.push(2)
	llist.push(1)
	print("Linked List before moving last to front ")
	llist.printList()
	
	# Function call
	llist.moveToFront()
	print("Linked List after moving last to front ")
	llist.printList()
