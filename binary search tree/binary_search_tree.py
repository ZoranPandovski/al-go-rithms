class Node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data

class BinaryTree:
    def __init__(self):
        self.root = None

    def insert(self, data):
        if self.root is None:
            self.root = Node(data)
        else:
            self._insert(data, self.root)

    def _insert(self, data, node):
        if data < node.data:
            if node.left is None:
                node.left = Node(data)
            else:
                self._insert(data, node.left)
        else:
            if node.right is None:
                node.right = Node(data)
            else:
                self._insert(data, node.right)

    def search(self, data):
        if self.root is not None:
            return self._search(data, self.root)
        else:
            return None

    def _search(self, data, node):
        if data == node.data:
            return node
        elif data < node.data and node.left is not None:
            return self._search(data, node.left)
        elif data > node.data and node.right is not None:
            return self._search(data, node.right)

    def traverse_in_order(self):
        if self.root is not None:
            self._traverse_in_order(self.root)

    def _traverse_in_order(self, node):
        if node is not None:
            self._traverse_in_order(node.left)
            print(node.data)
            self._traverse_in_order(node.right)
