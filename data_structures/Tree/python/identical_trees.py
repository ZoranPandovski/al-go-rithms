from __future__ import print_function
#  to determine if two trees are identical

from tree_utils import TreeNode


def identical_trees(root1, root2):
	if not root1 and not root2:
		return True
	elif root1 and root2:
		return (root1.data == root2.data) and \
				identical_trees(root1.left, root2.left) and \
				identical_trees(root1.right, root2.right)
	return False


def test():
	root1 = TreeNode(1)
	root2 = TreeNode(1)
	root1.left = TreeNode(2)
	root1.right = TreeNode(3)
	root1.left.left = TreeNode(4)
	root1.left.right = TreeNode(5)

	root2.left = TreeNode(2)
	root2.right = TreeNode(3)
	root2.left.left = TreeNode(4)
	root2.left.right = TreeNode(5)

	if identical_trees(root1, root2):
		print("Both trees are identical")
	else:
		print("Trees are not identical")
