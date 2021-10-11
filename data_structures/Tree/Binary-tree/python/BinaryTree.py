from __future__ import print_function
class Node:
    def __init__(self, key):
        self.right = None
        self.left = None
        self.key = key

    def addLeftChild(self, node):
        self.left = node

    def addRightChild(self, node):
        self.right = node


class BinaryTree:
    def getRootOfTree(self):
        root = Node(1)
        node2 = Node(2)
        node3 = Node(3)
        node4 = Node(4)
        node5 = Node(5)
        node6 = Node(6)
        node7 = Node(7)
        root.addLeftChild(node2)
        root.addRightChild(node3)
        node2.addLeftChild(node4)
        node2.addRightChild(node5)
        node3.addLeftChild(node6)
        node3.addRightChild(node7)
        return root


def inorder(node, array):
    if node is None:
        return array
    array = inorder(node.left, array)
    array.append(node.key)
    return inorder(node.right, array)


if __name__ == '__main__':
    # Create a Tree
    tree = BinaryTree()
    root = tree.getRootOfTree()
    # Print Inorder Traversal of Tree
    print('Inorder traversal for binary tree:', inorder(root, []))
