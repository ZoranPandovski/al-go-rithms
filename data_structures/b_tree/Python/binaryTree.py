"""
Implementation of binary tree
"""
from collections import deque


class Node(object):
    def __init__(self,data=None):
        self.val = data
        self.left = self.right = None


class BinaryTree(object):

    def insert(self,root,data):
        if root == None:
            root = Node(data)
            return root

        # Insert node by using breath first search
        queue = deque()
        queue.append(root)

        while len(queue):
            popped = queue.popleft()
            # The node to be inserted is already present in the tree
            if popped.val == data:
                return root
            if root.left:
                popped.append(root.left)
            else:
                node = Node(data)
                root.left = node
                return root

            if root.right:
                popped.append(root.right)
            else:
                node = Node(data)
                root.right = node
                return root


    def search(root,element):
        if root == None:
            return False
        if root.val == element:
            return True
        return self.search(root.left,element) or self.search(root.right,element)


    ## yet to code delete method
    def delete(self,root,data):
        pass


    def display(self,root):
        #preorder Traversal
        if root == None:
            return
        print root.val
        self.display(root.left)
        self.display(root.right)


    def size(self,root):
        if root == None:
            return 0
        return (1 + self.size(root.left) + self.size(root.right))
