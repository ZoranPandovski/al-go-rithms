class BinaryNode:
    def __init__(self ):
        self.data = None
        self.left = None
        self.right = None
        self.parent = None


class Binarytree:
    def __init__(self,data=None):
        self.root = BinaryNode()
        self.root.data = data
    def search(self,k):
        return self.searchtree(self.root,k)
    def searchtree(self,r=None,k=None):
        if r is None:
            return False
        if k == r.data:
            return True
        if k > r.data:
            return self.searchtree(r.right,k)
        if k < r.data:
            return self.searchtree(r.left,k)

    def treemin(self,t):
        #t = self.root
        while (t.left != None):
            t = t.left
        return t.data
    def treemax(self,r):
        #r = self.root
        while (r.right != None):
            r = r.right
        return r.data

    def treeSuc(self,x):
       # x = self.root
        if x.right != None:
            return self.treemin(x.right)
        y = x.parent
        while x != y.left and y != None:
            x = y
            y = y.parent
        return y.data

    def treePre(self,r):
        #r = self.root
        if r.left != None:
            return self.treemax(r.left)
        y = r.parent
        while y != None and r != y.right:
            r = y
            y = y.parent
        return y.data

    def Insert(self, v):
        t = BinaryNode()
        t.data=v
        t.left = t.right = t.parent = None
        x = self.root
        y = self.root.parent
        while (x != None):
            y = x
            if v <= x.data:
                x = x.left
            else:
                x = x.right
        t.parent = y
        if v < y.data:
            y.left = t
        else:
            y.right = t
    def delete(self,x):
        if x.right is None and x.left is None and x.parent is not None:
            if x.parent.data>x.data:
                x.parent.left=None
            else:
                x.parent.right=None
            #return
        elif (x.right is None and x.left is not None):
            if x.parent.data>x.data:
                x.parent.left=x.right
            else:
                x.parent.right=x.right
            #return
        elif x.left is None and x.right is not None and x.parent is not None:
            if x.parent.data>x.data:
                x.parent.left=x.left
            else:
                x.parent.right=x.left
            #return
        elif x.left is not None and x.right is not None:
            y=self.treePre1(x)
           # temp
            return self.delete(y)
def height(v):
    if v is None:
        return 0
    lh=1+height(v.left)
    rh=1+height(v.right)
    if lh>rh:
        return lh
    else:
        return rh
def printlevelorder(v):
    h=height(v)
    for i in range(1,h+1):
        printgivenlevel(v,i)
def printgivenlevel(v,level):
    if v is None:
        return
    if level==1:
        print(v.data)
    elif level>1:
        printgivenlevel(v.left,level-1)
        printgivenlevel(v.right,level-1)
def printpre(v):
    if v is None:
        return
    print(v.data)
    printpre(v.left)
    printpre(v.right)


b = Binarytree(10)
b.Insert(5)
b.Insert(14)
b.Insert(3)
b.Insert(8)
b.Insert(11)
b.Insert(6)
b.Insert(13)
b.Insert(7)
print(b.search(3))
printpre(b.root)
print("the predessor")
print(b.treePre(b.root))
print("the successor is ")
print(b.treeSuc(b.root))
print("the maximum in tree is ")
print(b.treemax(b.root))
print("the minimum in tree is ")
print(b.treemin(b.root))
b.delete(b.root.left.right)
print("after deleting the node")
printpre(b.root)
print("the level order traversal")
printlevelorder(b.root)
print("the height of the tree")
print(height(b.root))
