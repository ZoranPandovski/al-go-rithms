# create sample data to work with
# User is a class that allows us to enter the name, username, and the email for an user
class User:
    def __init__(self, username, name, email):
        self.username = username
        self.name = name
        self.email = email
        
    def __repr__(self):
        return "User(username='{}', name='{}', email='{}')".format(self.username, self.name, self.email)
    
    def __str__(self):
        return self.__repr__()

# making some instances of User to work with
aakash = User('aakash', 'Aakash Rai', 'aakash@example.com')
biraj = User('biraj', 'Biraj Das', 'biraj@example.com')
hemanth = User('hemanth', 'Hemanth Jain', 'hemanth@example.com')
jadhesh = User('jadhesh', 'Jadhesh Verma', 'jadhesh@example.com')
siddhant = User('siddhant', 'Siddhant Sinha', 'siddhant@example.com')
sonaksh = User('sonaksh', 'Sonaksh Kumar', 'sonaksh@example.com')
vishal = User('vishal', 'Vishal Goel', 'vishal@example.com')

# creating a list that contains all these User objects
users = [aakash, biraj, hemanth, jadhesh, siddhant, sonaksh, vishal]

# creating a node for the BST called BSTNode
class BSTNode():
    def __init__(self, key, value=None):
        self.key = key
        self.value = value
        self.left = None
        self.right = None
        self.parent = None
        

# creating a function to visualize a tree easily
def display_keys(node, space='\t', level=0):
    # print(node.key if node else None, level)
    
    # If the node is empty
    if node is None:
        print(space*level + '∅')
        return   
    
    # If the node is a leaf 
    if node.left is None and node.right is None:
        print(space*level + str(node.key))
        return
    
    # If the node has children
    display_keys(node.right, space, level+1)
    print(space*level + str(node.key))
    display_keys(node.left,space, level+1)    

# creating a function to find out the size of the tree
def tree_size(node):
    if node is None:
        return 0
    return 1 + tree_size(node.left) + tree_size(node.right)

# creating a function to insert a value in a BST
def insert(node, key, value):
    if node is None:
        node = BSTNode(key, value)
    elif key < node.key:
        node.left = insert(node.left, key, value)
        node.left.parent = node
    elif key > node.key:
        node.right = insert(node.right, key, value)
        node.right.parent = node
    return node

# creating a function to find a node given the key(username)
def find(node, key):
    if node is None:
        return None
    if key == node.key:
        return node
    if key < node.key:
        return find(node.left, key)
    if key > node.key:
        return find(node.right, key)

# creating a function to update a node value
def update(node, key, value):
    target = find(node, key)
    if target is not None:
        target.value = value

# creating a function to list all the nodes in the tree
def list_all(node):
    if node is None:
        return []
    return list_all(node.left) + [(node.key, node.value)] + list_all(node.right)

# creating a function to make a balanced BST (can replace insert operation)
def make_balanced_bst(data, lo=0, hi=None, parent=None):
    if hi is None:
        hi = len(data) - 1
    if lo > hi:
        return None
    
    mid = (lo + hi) // 2
    key, value = data[mid]

    root = BSTNode(key, value)
    root.parent = parent
    root.left = make_balanced_bst(data, lo, mid-1, root)
    root.right = make_balanced_bst(data, mid+1, hi, root)
    
    return root
    
# creating a function to balance an unbalanced tree
def balance_bst(node):
    return make_balanced_bst(list_all(node))

# summarizing all helper functions into a tree map
class TreeMap():
    def __init__(self):
        self.root = None
        
    def __setitem__(self, key, value):
        node = find(self.root, key)
        if not node:
            self.root = insert(self.root, key, value)
            self.root = balance_bst(self.root)
        else:
            update(self.root, key, value)
            
        
    def __getitem__(self, key):
        node = find(self.root, key)
        return node.value if node else None
    
    def __iter__(self):
        return (x for x in list_all(self.root))
    
    def __len__(self):
        return tree_size(self.root)
    
    def display(self):
        return display_keys(self.root)

# Sample test code for the TreeMap
# treemap = TreeMap()
# treemap.display()
# treemap['aakash'] = aakash
# treemap['jadhesh'] = jadhesh
# treemap['sonaksh'] = sonaksh
# treemap.display()
# print(treemap['jadhesh'])
# treemap['biraj'] = biraj
# treemap['hemanth'] = hemanth
# treemap['siddhant'] = siddhant
# treemap['vishal'] = vishal
# print(len(treemap))
# treemap.display()
# for key, value in treemap:
#     print(key, value)
# list(treemap)

# Some sample test code:
# tree = insert(None, jadhesh.username, jadhesh)
# insert(tree, biraj.username, biraj)
# insert(tree, sonaksh.username, sonaksh)
# insert(tree, aakash.username, aakash)
# insert(tree, hemanth.username, hemanth)
# insert(tree, siddhant.username, siddhant)
# insert(tree, vishal.username, siddhant)
# display_keys(tree)
# foundNode = find(tree, 'vishal')
# print(foundNode.key, foundNode.value)
# update(tree, 'siddhant', User('siddhant', 'Siddhant Raj', 'siddhant@raj.com'))
# foundNode = find(tree, 'siddhant')
# print(foundNode.key, foundNode.value)
# list_all(tree)
# data = [(user.username, user) for user in users]
# tree = make_balanced_bst(data)
# display_keys(tree)
