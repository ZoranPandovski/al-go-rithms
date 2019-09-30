"""
Return the maximum element in the tree, consisting only nodes of +ve value.
"""
import binary_search_tree
from collections import deque


def max_element_rec(root):

    if root == None:
        return -1

    temp = max(max_element(root.left),max_element(root.right))

    if root.val >= temp:
        maxi = root.val
    else:
        maxi = temp

    return maxi

def max_element(root):

    if root == None:
        return

    queue = deque()
    queue.append(root)
    maxi = root.val

    while len(queue):
        popped = queue.popleft()
        if (maxi < popped.val):
            maxi = popped.val
        if popped.left:
            queue.append(popped.left)
        if popped.right:
            queue.append(popped.right)

    return maxi


#                                 ### Testcases ###
#
# tree = binary_search_tree.Tree()
# root = tree.not_bst()
# print (max_element(root))
# print max_element(root)
