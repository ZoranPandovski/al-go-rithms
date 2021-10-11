from __future__ import print_function
# A recursive Python program to print REVERSE level order traversal 
  
# A binary tree node 
class Node: 
  
    # Constructor to create a new node 
    def __init__(self, data): 
        self.data = data 
        self.left = None
        self.right = None
  
# Function to print reverse level order traversal 
def reverseLevelOrder(root): 
    h = height(root) 
    for i in reversed(range(1, h+1)): 
        printGivenLevel(root,i) 
  
# Print nodes at a given level 
def printGivenLevel(root, level): 
  
    if root is None: 
        return 
    if level ==1 : 
        print(root.data, end=' ') 
  
    elif level>1: 
        printGivenLevel(root.left, level-1) 
        printGivenLevel(root.right, level-1) 
  
# Compute the height of a tree-- the number of  
# nodes along the longest path from the root node 
# down to the farthest leaf node 
def height(node): 
    if node is None: 
        return 0 
    else: 
  
        # Compute the height of each subtree 
        lheight = height(node.left) 
        rheight = height(node.right) 
  
        # Use the larger one 
        if lheight > rheight : 
            return lheight + 1
        else: 
            return rheight + 1
  
# Driver program to test above function 
root = Node(1) 
root.left = Node(2) 
root.right = Node(3) 
root.left.left = Node(4) 
root.left.right = Node(5) 
  
print("Level Order traversal of binary tree is")
reverseLevelOrder(root) 
  
