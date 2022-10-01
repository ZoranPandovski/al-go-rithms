from __future__ import print_function
class TreeNode(object):

	def __init__(self, data=None, left=None, right=None):
		self.data = data
		self.left = left
		self.right = right


class Traversals(object):

	def in_order_traversal(self, root):
		if root:
			self.in_order_traversal(root.left)
			print(str(root.data))
			self.in_order_traversal(root.right)

	def pre_order_traversal(self, root):
		if root:
			print(str(root.data))
			self.pre_order_traversal(root.left)
			self.pre_order_traversal(root.right)

	def post_order_traversal(self, root):
		if root:
			self.post_order_traversal(root.left)
			self.post_order_traversal(root.right)
			print(str(root.data))

	def level_order(self, root):
		level_queue = list()
		level_queue.append(root)
		while level_queue:
			current_node = level_queue.pop(0)
			print(current_node.data)
			if current_node.left:
				level_queue.append(current_node.left)
			if current_node.right:
				level_queue.append(current_node.right)



def test():
	l1 = TreeNode(4, None, None)
	l2 = TreeNode(5, None, None)
	l3 = TreeNode(6, None, None)
	l4 = TreeNode(7, None, None)
	l11 = TreeNode(2, l1, l2)
	l21 = TreeNode(3, l3, l4)
	root = TreeNode(1, l11, l21)
	traversal = Traversals()
	print("In-Order:")
	traversal.in_order_traversal(root)
	print("Pre-Order:")
	traversal.pre_order_traversal(root)
	print("Post-Order:")
	traversal.post_order_traversal(root)
	print("Level Order")
	traversal.level_order(root)


test()
