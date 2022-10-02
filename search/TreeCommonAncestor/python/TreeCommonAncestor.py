class Node:
# A Binary tree node
    # Constructor to create a new node
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None
 
def lca(root, n1, n2):
     
    # Base Case
    if root is None:
        return None
 
    if(root.data > n1 and root.data > n2):
        return lca(root.left, n1, n2)
 
    if(root.data < n1 and root.data < n2):
        return lca(root.right, n1, n2)
 
    return root

if __name__ == "__main__":
    root = Node(20)
    root.left = Node(8)
    root.right = Node(22)
    root.left.left = Node(4)
    root.left.right = Node(12)
    root.left.right.left = Node(10)
    root.left.right.right = Node(14)
    
    n1 = 12 ; n2 = 18
    t = lca(root, n1, n2)
    print(f"LCA of {n1} and {n2} is {t.data}")
    
    n1 = 16 ; n2 = 10
    t = lca(root, n1, n2)
    print(f"LCA of {n1} and {n2} is {t.data}")
    
    n1 = 18 ; n2 = 22
    t = lca(root, n1, n2)
    print(f"LCA of {n1} and {n2} is {t.data}")