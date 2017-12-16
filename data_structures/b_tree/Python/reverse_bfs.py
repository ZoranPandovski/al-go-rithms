"""
Print the tree level by level from the leaf to root
Time Complexity - O(n)
Space Complexity - O(n)
"""

from collections import deque
import binary_search_tree


def reverse_bfs(root):

    if root == None:
        return []

    q = deque()
    q.append(root)
    stack = list()

    while(len(q) != 0):

        popped = q.popleft()
        stack.append(popped.val)

        if popped.right:
            q.append(popped.right)
        if popped.left:
            q.append(popped.left)

    # Popping the stack, will print the tree in a reversed bfs order
    return stack


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
# print reverse_bfs(root)
