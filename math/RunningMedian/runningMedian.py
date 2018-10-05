class Node:
    def __init__(self,key):
        self.left=None
        self.right=None
        self.data=key
        self.bf=0
        self.count=1
        self.parent=None
        self.lkids=0
        self.rkids=0

def rotateNBalance(node):
    if node.bf < 0:
        if node.right.bf <= 0:
            rotateLeft(node)
        else:
            rotateRight(node.right)
            rotateLeft(node)
    elif node.bf > 0:
        if node.left.bf >=0:
            rotateRight(node)
        else:
            rotateLeft(node.left)
            rotateRight(node)

def rotateLeft(node):
    newNode=node.right
    node.right=newNode.left
    if newNode.left:
        newNode.left.parent=node
    if node.parent:
        newNode.parent=node.parent
    if node.parent is None: # means node is root
        global rootNode
        newNode.parent=None
        rootNode=newNode
    else:
        if node.parent.left==node:
            node.parent.left=newNode
        else:
            node.parent.right=newNode
    newNode.left=node
    node.parent=newNode
    node.rkids=newNode.lkids
    newNode.lkids+=node.lkids+node.count
    node.bf=node.bf+1-min(0,newNode.bf)
    newNode.bf=newNode.bf+1+max(0,node.bf)

def rotateRight(node):
    newNode=node.left
    node.left=newNode.right
    if newNode.right:
        newNode.right.parent=node
    if node.parent:
        newNode.parent=node.parent
    if node.parent is None:
        global rootNode
        newNode.parent=None
        rootNode=newNode
    else:
        if node.parent.left==node:
            node.parent.left=newNode
        else:
            node.parent.right=newNode
    newNode.right=node
    node.parent=newNode
    node.lkids=newNode.rkids
    newNode.rkids+=node.rkids+node.count
    node.bf=node.bf-1-max(0,newNode.bf)
    newNode.bf=newNode.bf-1+min(0,node.bf)

def updateBF(node):
    if(node.bf > 1 or node.bf < -1):
        rotateNBalance(node)
        return
    if node.parent:
        if node==node.parent.left:
            node.parent.bf+=1
        elif node==node.parent.right:
            node.parent.bf-=1
        if node.parent.bf!=0:
            updateBF(node.parent)
def insert(root,node):
    if root is None:
        global rootNode
        rootNode = node
    else:
        if(node.data==root.data):
            root.count+=1
            return
        if(node.data < root.data):
            root.lkids+=1
            if root.left is None:
                node.parent=root
                root.left=node
                updateBF(node)
            else:
                insert(root.left,node)
        else:
            root.rkids+=1
            if root.right is None:
                node.parent=root
                root.right=node
                updateBF(node)
            else:
                insert(root.right,node)

def kth(root,x):
    if(x == root.lkids+root.count):
        return root
    elif(x<root.lkids+root.count):
        if(root.lkids==0 or root.lkids<x):
            return root
        return kth(root.left,x)
    else:
        if(root.rkids==0):
            return root
        return kth(root.right,x-root.lkids-root.count)

N=int(input())      # number of elements to be inserted
rootNode=None
for i in range(1,N+1):
    x=int(input())  
    insert(rootNode,Node(x)) # insert an element in AVL tree
    m=kth(rootNode,(i//2)+1)    #find k+1th minimum
    if(i&1):
        print(float(m.data))    # print if total nodes are odd
    else:
        m2=kth(rootNode,(i//2)) # find kth minimum
        print(float((m.data+m2.data)/2))    # print avg of 2 median if total nodes are even