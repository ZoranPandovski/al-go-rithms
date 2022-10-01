from __future__ import print_function
import sys
from tree_utils import *


# Finding maximum element in a binary tree
def find_max(root):
	max_val = -sys.maxint -1
	if root:
		root_val = root.data
		left_val = find_max(root.left)
		right_val = find_max(root.right)
		if left_val > right_val:
			max_val = left_val
		else:
			max_val = right_val
		if max_val < root_val:
			max_val = root_val
	return max_val


# Finding an element in Binary Tree
def find_element(root, data):
	if root:
		if root.data == data:
			return 1
		else:
			temp = find_element(root.left, data)
			if temp != 0:
				return temp
			else:
				return find_element(root.right, data)
	return 0


# Finding size of tree : Number of nodes in tree
def size_of_tree(root):
	if not root:
		return 0
	else:
		left_size = size_of_tree(root.left)
		right_size = size_of_tree(root.right)
		return left_size + 1 + right_size


# Printing level order data in reverse order : 1 2 3 4 5 6 7 -> 4 5 6 7 2 3 1
def reverse_level_order(root):
	level_queue = list()
	level_stack = list()
	level_queue.append(root)
	while level_queue:
		curr_node = level_queue.pop(0)
		if curr_node.right:
			level_queue.append(curr_node.right)
		if curr_node.left:
			level_queue.append(curr_node.left)
		level_stack.append(curr_node)
	while level_stack:
		curr_node = level_stack.pop()
		print(curr_node.data, end=' ')


# LeftView of Tree
def left_view_of_tree(root):
	if root:
		print(root.data)
		if root.left:
			left_view_of_tree(root.left)
		else:
			left_view_of_tree(root.right)


# Height of Tree
def height_of_tree(root):
	if not root:
		return -1
	else:
		left_height = height_of_tree(root.left)
		right_height = height_of_tree(root.right)
		if left_height > right_height:
			max_height = left_height + 1
		else:
			max_height = right_height + 1
		return max_height


# Bottom View of Tree
def bottom_view(root):
	if root:
		bottom_view(root.left)
		if not root.left and not root.right:
			print(root.data)
		bottom_view(root.right)


# Leaf Node Count
def get_leaf_node_count(root):
	if not root:
		return 0

	if root.left is None and root.right is None:
		return 1
	else:
		return get_leaf_node_count(root.left) + get_leaf_node_count(root.right)

def test():
	# l1 = TreeNode(4, None, None)
	# l2 = TreeNode(5, None, None)
	# l3 = TreeNode(6, None, None)
	# l4 = TreeNode(7, None, None)
	# l11 = TreeNode(2, l1, l2)
	# l21 = TreeNode(3, l3, l4)
	# root = TreeNode(1, l11, l21)

	root = TreeNode(3)
	root.left = TreeNode(2)
	root.right = TreeNode(5)
	root.left.left = TreeNode(1)
	root.left.right = TreeNode(4)

	# print "find_element:", find_element(root, 6)
	# print "size_of_tree", size_of_tree(root)
	# print "reverse_level_order: "
	# reverse_level_order(root)
	# print "left_view: "
	# left_view_of_tree(root)
	# print "height: "
	# print height_of_tree(l1)
	bottom_view(root)
	print("Leaf:",get_leaf_node_count(root))
