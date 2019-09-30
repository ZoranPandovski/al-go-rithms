"""
Return the size of the tree (i.e) number of nodes in the tree
"""

from binary_search_tree import Tree
import random

class TreeSize():

    def tree_size(self,root):
        if root == None:
            return 0

        return ( 1 + self.tree_size(root.left) + self.tree_size(root.right))


                                    ## Testcases ###

# tsize = TreeSize()
# root = None
# obj = Tree()
#
#
# # Create a sample tree
# for i in range(10):
#     rand = random.randrange(1,20,2)
#     root = obj.insert(root,rand)
#
# print tsize.tree_size(root)
