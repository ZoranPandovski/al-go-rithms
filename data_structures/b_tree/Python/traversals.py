"""
DFS Binary Tree Traversals
"""
from binaryTree import testcaseBST

class Traversal:
    def postOrder(self, root):
        pass


    def inOrder(self, root):
        stack = list()
        node = root
        result = []

        while (len(stack)):
            if node:
                stack.append(node)
                node = node.left
            else:
                current = stack.pop()
                result.append(current.data)
                node = current.right
        return result


    def preOrder(self, root):
        stack = list()
        result = []
        stack.append(root)

        while(len(stack)):
            current = stack.pop()
            result.append(current.val)
            if current.right:
                stack.append(current.right)
            if current.left:
                stack.append(current.left)
        return result
