class Node:
    def __init__(self, data=None):
        self.data = data
        self.right = None
        self.left = None
        self.mid = None


class TST:
    def __init__(self):
        self.root = Node()
        self.leaf = None

    @staticmethod
    def _search(node, leaf):
        while node:
            if node.data == leaf:
                return node
            if leaf < node.data:
                node = node.left
            else:
                node = node.right
        return None

    def _insert(self, node, leaf):
        if node is None:
            return leaf
        elif leaf.data == node.data:
            return node
        elif leaf.data < node.data:
            node.left = self._insert(node.left, leaf)
        else:
            node.right = self._insert(node.right, leaf)
        return node

    def insert(self, word):
        node = self.root
        for char in word:
            child = self._search(node.mid, char)
            if not child:  # not null
                # create a new node
                child = Node(char)
                node.eq = self._insert(node.mid, child)
            node = child
        if not self._search(node.mid, self.leaf):  # not null
            node.mid = self._insert(node.mid, Node(self.leaf))

    def search(self, word):
        node = self.root
        for c in word:
            node = self._search(node.eq, c)
            if not node:
                return False
        return self._search(node.mid, self.leaf) is not None

    def _traverse(self, node, leaf):
        if node:
            for c in self._traverse(node.left, leaf):
                return c
            if node.data == leaf:
                return []
            else:
                for c in self._traverse(node.eq, leaf):
                    return [node.data] + c
            for c in self._traverse(node.right, leaf):
                return c

    def traverse(self):
        for w in self._traverse(self.root.eq, self.leaf):
            print(''.join(w))

    def common_prefix(self, chars):
        node = self.root
        buff = []
        for char in chars:
            buff.append(char)
            node = self._search(node.eq, char)
            if not node:
                return
        for x in self._traverse(node.eq, self.leaf):
            yield ''.join(buff + x)


if __name__ == '__main__':
    """
    tst = TST()
    names = ['arun', 'ari', 'aari', 'aruna']
    for name in names:
        tst.insert(name)
    print(tst.search('nithya'))
    print(tst.search('aari'))
    tst.traverse()
    """
    #Just in case you would like to work on files
    #Search for elements with common prefix
    tst = TST()
    with open('./dict.txt', 'r+') as dictionary:
        for entry in dictionary.readlines():
            tst.insert(entry.rstrip())
    for item in tst.common_prefix('sa'):
        print(item)
