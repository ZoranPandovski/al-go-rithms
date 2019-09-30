"""
Return true, if both the tree have the same structure and same data in it. Else return False
"""
import random
from binary_search_tree import Tree


class SameTree():

    def same_tree(self,root1,root2):

        if root1 == None and root2 == None:
            return True

        if (root1 == None or root2 == None):
            return False

        if root1.val == root2.val:
            if self.same_tree(root1.left,root2.left):
                if self.same_tree(root1.right,root2.right):
                    return True

        return False


                                    ### Testcases ###

# stree = SameTree()
# root1 = None
# root2 = None
# obj = Tree()
#
#
# # Create exact same tree
# for i in range(10):
#     rand = random.randrange(1,20,2)
#     root1 = obj.insert(root1,rand)
#     root2 = obj.insert(root2,rand)
#
#
# print stree.same_tree(root1,root2)
#
#
# root1 = None
# root2 = None
#
# # Create a tree with same structure but different data in it
# for i in range(10):
#     rand1 = random.randrange(1,20,2)
#     rand2 = random.randrange(1,20,2)
#     root1 = obj.insert(root1,rand1)
#     root2 = obj.insert(root2,rand2)
#
# print stree.same_tree(root1,root2)
#
#
# root1 = None
# root2 = None
#
# # Create a tree with totally different tree structure
# for i in range(4):
#     rand = random.randrange(1,20,4)
#     root1 = obj.insert(root1,rand)
# for i in range(6):
#     rand = random.randrange(1,20,4)
#     root2 = obj.insert(root2, rand)
#
# print stree.same_tree(root1, root2)
