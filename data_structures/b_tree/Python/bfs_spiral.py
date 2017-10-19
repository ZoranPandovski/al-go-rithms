"""
Print the tree level by level in spiral order
Time Complexity - O(n)
Space Complexity - O(n)
"""

from collections import deque
import binary_search_tree

def bfs_spiral(root):

    if root == None:
        return []

    stack1 = list()
    stack2 = list()
    result = []
    stack1.append(root)

    # left acts as a flag for spiral order
    left = True
    # target tells to which stack the elements shoud be pushed
    target = 2

    while (len(stack1) or len(stack2)):

        if target == 2:
            while (len(stack1)):
                popped = stack1.pop()
                result.append(popped.val)
                if (left):
                    if popped.left:
                        stack2.append(popped.left)
                    if popped.right:
                        stack2.append(popped.right)
                else:
                    if popped.right:
                        stack2.append(popped.right)
                    if popped.left:
                        stack2.append(popped.left)

            target = 1
            left = not(left)

            continue

        if target == 1:
            while (len(stack2)):
                popped = stack2.pop()
                result.append(popped.val)
                if (left):
                    if popped.left:
                        stack1.append(popped.left)
                    if popped.right:
                        stack1.append(popped.right)
                else:
                    if popped.right:
                        stack1.append(popped.right)
                    if popped.left:
                        stack1.append(popped.left)

            target = 2
            left = not(left)

    return result


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
# print bfs_spiral(root)
