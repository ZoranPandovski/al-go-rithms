class Node:
    def __init__(self, key, left=None, right=None, parent=None):
        self.key = key
        self.right = right
        self.left = left

    def hasLeftChild(self):
        return self.left

    def hasRightChild(self):
        return self.right

    def isLeaf(self):
        return not (self.right or self.left)

    def isRoot(self):
        return not self.parent

    def __str__(self):
        return self.key


class Tree:
    def __init__(self):
        self.root = None
        self.size = 0

    def _addNode(self, current, value):
        if value < current.key:
            if current.left != None:
                self._addNode(current.left, value)
            else:
                current.left = Node(value, parent=current)
        if value > current.key:
            if current.right != None:
                self._addNode(current.right, value)
            else:
                current.right = Node(value, parent=current)

    def addNode(self, value):
        if self.root == None:
            self.root = Node(value)
        else:
            self._addNode(self.root, value)
        self.size += 1

    def _search(self, current, value):
        if current == None:
            print("searched value is not in tree")
            return None
        if current.key == value:
            print("value found")
            return current
        elif current.key < value:
            return self._search(current.right, value)
        elif current.key > value:
            return self._search(current.left, value)

    def search(self, value):
        return self._search(self.root, value)

    def getMin(self, current):
        if current == None:
            return None
        if current.left == None:
            return current
        else:
            return self.getMin(current.left)

    def _deleteNode(self, current, value):
        if current == None:
            return None
        if current.key < value:
            current.right = self._deleteNode(current.right, value)
        elif current.key > value:
            current.left = self._deleteNode(current.left, value)
        else:
            if current.left == None:
                tmp = current.right
                del current
                return tmp
            if current.right == None:
                tmp = current.left
                del current
                return tmp
            replacedNode = self.getMin(current.right)
            current.key = replacedNode.key
            current.right = self._deleteNode(current.right, replacedNode.key)
        return current

    def deleteNode(self, value):
        self._deleteNode(self.root, value)

    def _prtTree(self, current):
        if current == None:
            return
        print(current.key)
        self._prtTree(current.left)
        self._prtTree(current.right)

    def prtTree(self):
        self._prtTree(self.root)
