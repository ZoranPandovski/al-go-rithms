class Node(object):
    
    def __init__(self, **kwargs):
        self.value      = kwargs.get('value')
        self.children   = []

    def __str__(self):
        return 'Val: {0} Children: {1}'.format(self.value, self.children)

    def __hash__(self):
        return hash((self.value, self.children,))

    __repr__ = __str__

class nAryTree(object):

    def __init__(self):
        self._root = Node()

    def getRoot(self):
        return self._root

    def insert(self, data):
        self._insertValues(data, self._root)

    def _insertValues(self, data, currNode):
        if not data:
            return
        
        if currNode and not currNode.value:
            tmpChild = None

            for child in currNode.children:
                if data[0] == child.value:
                    tmpChild = child
                    break

            if tmpChild:
                self._insertValues(data, tmpChild)
            else:
                newNode = Node(value=data[0])
                currNode.children.append(newNode)
                self._insertValues(data, newNode)
        else:
            if len(data) > 1:
                tmpChild = None

                for child in currNode.children:
                    if data[1] == child.value:
                        tmpChild = child
                        break
                
                if tmpChild:
                    self._insertValues(data[1:], tmpChild)
                else:
                    newNode = Node(value=data[1])
                    currNode.children.append(newNode)
                    self._insertValues(data[1:], newNode)

    def show(self):
        self.showContainer = []
        self._showTree(self._root)

    def _showTree(self, currNode):
        if currNode and not currNode.value:
            print '*Root'
        else:
            self.showContainer.append('--')
            self.showContainer.append(currNode.value)
            print ''.join(self.showContainer)
            self.showContainer.pop()
            self.showContainer.pop()

        if currNode and currNode.children:
            self.showContainer.append('  |')
            print ''.join(self.showContainer)
        
        for child in currNode.children:
            self._showTree(child)

        if currNode.children and self.showContainer:
            self.showContainer.pop()

    def deleteNode(self, tgt=''):
        searchContainer = []
        result          = {}
        res             = self._search(self._root, tgt, searchContainer, None, result)
        parentNode      = result.get('parentNode')

        for idx in xrange(len(parentNode.children)):
            if parentNode.children[idx].value == tgt:
                del parentNode.children[idx]
                break

        return searchContainer[1:]

    def searchTree(self, tgt=''):
        searchContainer = []
        res             = self._search(self._root, tgt, searchContainer)

        return searchContainer[1:]

    def _search(self, currNode, tgt, path=[], parentNodeOfTgt=None, result={}):
        if (not tgt and tgt.strip()) or not currNode:
            return False

        if currNode.value == tgt:
            path.append(currNode.value)
            result['parentNode']    = parentNodeOfTgt
            result['tgtNode']       = currNode
            print 'Path: {0}'.format('>'.join(path))

            return True
        else:
            path.append(currNode.value if currNode.value else 'Root')
            for child in currNode.children:
                if self._search(child, tgt, path, currNode, result):
                    return True
            else:
                path.pop()

    def nestedTuples(self):
        data = self._naryToNestedTuples(self._root)
        return data[1] if data else ()

    def _naryToNestedTuples(self, t):
        return (t.value, tuple(map(self._naryToNestedTuples, t.children)), ) if t.children and isinstance(t.children, (tuple, list,)) \
            else t.value

    def nestedLists(self):
        data = self._naryToNestedLists(self._root)
        return data[1] if data else []

    def _naryToNestedLists(self, t):
        return [t.value, map(self._naryToNestedLists, t.children)] if t.children and isinstance(t.children, (tuple, list,)) \
            else t.value

def main():
    tree = nAryTree()
    tree.insert(('A', 'B', 'C', 'D',))
    tree.insert(('A', 'B', 'C', 'E',))
    tree.insert(('A', 'B', 'F', 'X',))
    tree.insert(('A', 'B', 'C', 'Y',))
    tree.show()

    tree.searchTree('X')

if __name__ == '__main__':
    main()
