"""
Print the tree by traversing in a BFS manner
"""
from __future__ import print_function

from collections import deque
import binary_search_tree


def print_bfs(root):

    if root == None:
        return

    q = deque()
    q.append(root)
    node = binary_tree.Node('$')  # noqa: F821 TODO!
    q.append(node)

    while len(q) != 0:

        # Base condition to exit, once all elements are printed
        if (len(q) == 1 and q[0].val == '$'):
            return

        while(q[0].val != '$'):
            popped = q.popleft()

            if popped.left:
                q.append(popped.left)
            if popped.right:
                q.append(popped.right)

            print(popped.val, ' ', end=' ')

        # Prints new line
        print()
        # Enqueues '$'
        q.append(node)
        # Dequeues'$'
        q.popleft()



                                    ### Testcases ###

# root = None
# tree = binary_search_tree.Tree()
# root = tree.not_bst()
# print_bfs(root)
