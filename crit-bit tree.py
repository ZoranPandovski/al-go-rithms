# Define a class for the nodes in the tree
class CritBitNode:
    def _init_(self, key=None, terminal=False):
        self.key = key
        self.left_child = None
        self.right_child = None
        self.terminal = terminal

# Define a class for the tree
class CritBitTree:
    def _init_(self):
        self.root = None

    # Insert a key into the tree
    def insert(self, key):
        if self.root is None:
            self.root = CritBitNode(key)
        else:
            current_node = self.root
            while True:
                if key < current_node.key:
                    if current_node.left_child is None:
                        current_node.left_child = CritBitNode(key)
                        break
                    else:
                        current_node = current_node.left_child
                else:
                    if current_node.right_child is None:
                        current_node.right_child = CritBitNode(key)
                        break
                    else:
                        current_node = current_node.right_child
            current_node.terminal = True

    # Search for a key in the tree
    def search(self, key):
        current_node = self.root
        while current_node is not None:
            if key == current_node.key:
                return current_node.terminal
            elif key < current_node.key:
                current_node = current_node.left_child
            else:
                current_node = current_node.right_child
        return False
