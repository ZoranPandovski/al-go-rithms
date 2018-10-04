"""
Breadth first Search or Level Order Traversal
"""
from collections import deque
import binary_search_tree


def bfs(root):

    if root == None:
        return None

    q = deque()
    q.append(root)
    result = list()

    while (len(q) != 0):
        popped = q.popleft()
        result.append(popped.val)

        if popped.left != None:
            q.append(popped.left)
        if popped.right != None:
            q.append(popped.right)

    print result

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
# bfs(root)
