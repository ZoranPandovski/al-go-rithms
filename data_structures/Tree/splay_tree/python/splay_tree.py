#!/bin/python3
import unittest

class Node:
    __slots__ = ('key','left','right')
    def __init__(self, key):
        self.key   = key
        self.left  = None
        self.right = None

class SplayTree:
    __slots__ = ('root','header')

    def __init__(self):
        self.root   = None
        self.header = Node(None)
    
    def printTree(self,r=None):
        if r==None:
            print("node -> left,right: ")
            r=self.root
        if r:
            print( r.key, "->", r.left.key if r.left!=None else "*", " , " , r.right.key if r.right!=None else "*" )
            if r.left!=None: 
                self.printTree( r.left )
            if r.right!=None: 
                self.printTree( r.right )
        return ""

    #Iterative 
    #NOTE: no duplicate keys!
    def insert(self, key):
        if (self.root == None):
            self.root = Node(key)
            return

        root=self.splay(key, self.root)

        if root.key == key:
            # If the key is already there in the tree, don't do anything.
            return

        node=Node(key)
        if key < root.key:
            #insert between root and left
            node.left, node.right, root.left = root.left, root, None 
        else:
            #insert between root and right
            node.left, node.right, root.right= root, root.right, None 
        self.root = node

    def remove(self, key):
        if (self.root == None):
            return None
        root=self.splay(key,self.root)
        if key != root.key:
            raise 'key not found in tree'
            return root

        # Now delete the root.
        if root.left == None:
            root = root.right
        else:
            x = root.right
            root = self.splay(key, root.left)
            root.right = x
        self.root=root
        return root

    def findMin(self):
        if self.root == None:
            return None
        x = self.root
        while x.left != None:
            x = x.left
        self.splay(x.key,self.root)
        return x

    def findMax(self):
        if self.root == None:
            return None
        x = self.root
        while (x.right != None):
            x = x.right
        self.splay(x.key,self.root)
        return x

    def find(self, key):
        if self.root == None:
            return None
        self.splay(key,self.root)
        if self.root.key != key:
            return None
        return self.root

    def isEmpty(self):
        return self.root == None

    #RR(Y rotates to the right):
    #        k2                   k1
    #       /  \                 /  \
    #      k1   Z     ==>       X   k2
    #     / \                      /  \
    #    X   Y                    Y    Z

    def splayRR(self,k2):
        k1  = k2.left
        k2.left = k1.right
        k1.right = k2
        return k1

    #LL(Y rotates to the left):
    #        k2                       k1
    #       /  \                     /  \
    #      X    k1         ==>      k2   Z
    #          /  \                /  \
    #         Y    Z              X    Y
    # 
    def splayLL(self,k2):
        k1=k2.right
        k2.right=k1.left
        k1.left=k2
        return k1


    #Top-down splay tree 
    #If key is in the tree, then make it root
    #If not - last checked will be rotated to root.
    def splay(self, key, root):
        if root==None:
            return None

        LTree=RTree=Header=self.header
        Header.left=Header.right=None
        #Node(None)

        #Iterative approach
        #loop until child == NULL or key found
        #The zig/zag mode would only happen when cannot find key and will reach null on one side after RR or LL Rotation.
        while True:
            if key < root.key:
                #go left
                if root.left == None:
                    break
                if key < root.left.key:
                    #root=self.splayRR(root)
                    k1  = root.left
                    root.left = k1.right
                    k1.right = root
                    root=k1
                    if root.left==None:
                        break
                #Link to R Tree
                RTree.left = root
                RTree      = root
                root       = root.left
                #RTree.left = None
            elif key > root.key:
                #go right
                if root.right == None:
                    break
                if key > root.right.key:
                    #root =self.splayLL(root)
                    k1=root.right
                    root.right=k1.left
                    k1.left=root
                    root=k1
                    if root.right==None:
                        break
                #Link to R Tree
                LTree.right = root
                LTree       = root
                root        = root.right
                #LTree.right = None
            else:
                #key equal to root - found
                break
        #assemble LTree, MidTree and Rtree
        LTree.right=root.left
        RTree.left =root.right
        root.left  =Header.right
        root.right =Header.left
        self.root=root
        return root


class TestCase(unittest.TestCase):
    def setUp(self):
        self.keys = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
        self.t = SplayTree()
        for key in self.keys:
            self.t.insert(key)
            #self.t.printTree()
        
    def testInsert(self):
        for key in self.keys:
            self.assertEqual(key, self.t.find(key).key)

    def testRemove(self):
        for key in self.keys:
            self.t.remove(key)
            self.assertEqual(self.t.find(key), None)

    def testLargeInserts(self):
        t = SplayTree()
        nums = 40000
        gap = 307
        i = gap
        while i != 0:
            t.insert(i)
            i = (i + gap) % nums

    def testIsEmpty(self):
        self.assertFalse(self.t.isEmpty())
        t = SplayTree()
        self.assertTrue(t.isEmpty())

    def testMinMax(self):
        self.assertEqual(self.t.findMin().key, 0)
        self.assertEqual(self.t.findMax().key, 9)

if __name__ == "__main__":
    keys = [1, 5, 2, 9, 4, 0, 6, 7, 8, 3]
    t = SplayTree()
    for key in keys:
        t.insert(key)
        t.printTree()
    t.insert(5)
    t.printTree()
    t.remove(0)
    t.printTree()
    for key in [2,4,6,8]:
        print(key, t.find(key))
        t.printTree()
    print(t.findMin())
    print(t.findMax())
    unittest.main()
