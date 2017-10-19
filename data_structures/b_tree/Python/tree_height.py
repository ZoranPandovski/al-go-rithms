"""
Return the height of the binary search tree
"""

import random
from binary_search_tree import Tree

class TreeHeight():

    def tree_height(self,root):
        if root == None:
            return 0

        return ( 1 +  max(self.tree_height(root.left) , self.tree_height(root.right)))


                                    ## Testcases ###

# theight = TreeHeight()
# root = None
# obj = Tree()
#
#
# # Create a sample tree
# for i in range(10):
#     rand = random.randrange(1,20,2)
#     root = obj.insert(root,rand)
#
# obj.preorder(root)
# print theight.tree_height(root)
#
# root = None
# root = obj.insert(root, 4)
# root = obj.insert(root, 3)
# root = obj.insert(root, 6)
# root = obj.insert(root, 5)
# root = obj.insert(root, 7)
#
# print theight.tree_height(root)
