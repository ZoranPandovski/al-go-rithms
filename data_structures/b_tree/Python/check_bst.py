"""
Check whether the given binary tree is BST(Binary Search Tree) or not
"""

import binary_search_tree

def check_bst(root):

    if(root.left != None):
        temp = root.left
        if temp.val <= root.val:
            left = check_bst(root.left)
        else:
            return False
    else:
        left = True

    if(root.right != None):
        temp = root.right
        if temp.val > root.val:
            right = check_bst(root.right)
        else:
            return False
    else:
        right = True


    if (left and right):
        return True
    else:
        return False



#                                     ### Testcases ###
#
# root = None
# tree = binary_search_tree.Tree()
#
# # This tree should return Tree
# root = tree.insert(root, 6)
# root = tree.insert(root,3)
# root = tree.insert(root,1)
# root = tree.insert(root,4)
# root = tree.insert(root,8)
# root = tree.insert(root,7)
# root = tree.insert(root,9)
# tree.preorder(root)
# print check_bst(root)
#
# # This tree should return False
# root = tree.not_bst()
# print check_bst(root)
