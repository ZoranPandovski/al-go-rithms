"""
Return the lowest common ancestor for the given two nodes in the binary search tree
Time Complexity - O(log n)
Space Complexity - O(1)
"""

import binary_search_tree

def lca(root,a,b):

    if root.val == a or root.val == b:
        return root.val
    if root.val > a and root.val < b:
        return root.val
    if root.val < a and root.val > b:
        return root.val
    if root.val < a and root.val < b:
        return lca(root.right, a, b)
    if root.val > a and root.val > b:
        return lca(root.left, a, b)


                                    ### Testcases ###

# root = None
# tree = binary_search_tree.Tree()
#
# root = tree.insert(root,4)
# root = tree.insert(root,2)
# root = tree.insert(root,3)
# root = tree.insert(root,1)
# root = tree.insert(root,6)
# root = tree.insert(root,5)
# root = tree.insert(root,7)
#
# tree.preorder(root)
# print lca(root,3,6)
