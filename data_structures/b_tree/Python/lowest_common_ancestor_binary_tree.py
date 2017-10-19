"""
Return the lowest common ancestor in a binary tree
"""

import binary_search_tree

def lca(root,a,b):

    if root == None:
        return None

    if root.val == a or root.val == b:
        return root.val

    left = lca(root.left, a, b)
    right = lca(root.right, a, b)

    if left != None and right != None:
        return root.val

    if left == None and right == None:
        return None

    if left:
        return left

    if right:
        return right


                                    ### Testcases ###
#
# tree = binary_search_tree.Tree()
# root = tree.not_bst()
# tree.preorder(root)
# print lca(root,7,8)
# print lca(root,8,1)
# print lca(root,5,1)
# print lca(root,3,6)
