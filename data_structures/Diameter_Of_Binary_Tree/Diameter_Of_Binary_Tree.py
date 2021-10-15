'''
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        def diameterTreeUtil(root):
            if root == None: return [0,0]
            
            leftTree = diameterTreeUtil(root.left)
            rightTree = diameterTreeUtil(root.right)
            
            internalPath = max(leftTree[1],rightTree[1])
            if leftTree[0] + rightTree[0] + 1 > internalPath: internalPath = leftTree[0] + rightTree[0] + 1
            
            return [max(leftTree[0],rightTree[0])+1,internalPath]
        
        if root == None: return 0
        result = diameterTreeUtil(root)
        return max(result)-1