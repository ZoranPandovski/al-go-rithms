# Tree_sort algorithm
# Build a BST and in order traverse.

class node():
    # BST data structure
    def __init__(self, val):
        self.val = val
        self.left = None 
        self.right = None 
    
    def insert(self,val):
        if self.val:
            if val < self.val:
                if self.left == None:
                    self.left = node(val)
                else:
                    self.left.insert(val)
            elif val > self.val:
                if self.right == None:
                    self.right = node(val)
                else:
                    self.right.insert(val)
        else:
            self.val = val

def inorder(root, res):
    # Recursive travesal 
    if root:
        inorder(root.left,res)
        res.append(root.val)
        inorder(root.right,res)

def treesort(arr):
    # Build BST
    if len(arr) == 0:
        return arr
    root = node(arr[0])
    for i in range(1,len(arr)):
        root.insert(arr[i])
    # Traverse BST in order. 
    res = []
    inorder(root,res)
    return res

print(treesort([10,1,3,2,9,14,13]))