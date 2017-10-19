""" Binary Search Tree """

import random


# Defining node
class Node(object):
    def __init__(self,val=None):
        self.val = val
        self.left = None
        self.right = None

# Operations performed on the tree
class Tree(object):

    def insert(self,root,val):
        if root == None:
            root = Node(val=val)
            return root
        if(root.val >= val):
            root.left = self.insert(root.left,val)
        elif (root.val < val):
            root.right = self.insert(root.right,val)
        return root


    def preorder(self,root):
        if root != None:
            print root.val
            self.preorder(root.left)
            self.preorder(root.right)


    def postorder(self,root):
        if root != None:
            self.postorder(root.left)
            self.postorder(root.right)
            print root.val


    def inorder(self,root):
        if root != None:
            self.inorder(root.left)
            print root.val
            self.inorder(root.right)


def testcaseBST(self):
    root = None
    binaryTree = BinaryTree()
    binaryTree.insert(root, 5)
    binaryTree.insert(root, 3)
    binaryTree.insert(root, 2)
    binaryTree.insert(root, 4)
    binaryTree.insert(root, 6)
    return binaryTree


def testcaseNonBST(self):
    root = Node(3)
    l_h1 = Node(6)
    r_h1 = Node(8)
    root.left = l_h1
    root.right = r_h1

    l1_h2 = Node(7)
    l_h1.left = l1_h2
    l_h1.right = None
    l1_h2.left = l1_h2.right = None

    l3_h2 = Node(5)
    l4_h2 = Node(1)
    l3_h2.left = l3_h2.right = l4_h2.left = l4_h2.right = None
    r_h1.left = l3_h2
    r_h1.right = l4_h2

    return root
