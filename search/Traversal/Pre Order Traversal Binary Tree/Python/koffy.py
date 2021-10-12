#Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def preorderTraversal(self, root: TreeNode):
        result = []
        if root:
            result.append(root.val)
            result += self.inorderTraversal(root.left)
            result += self.inorderTraversal(root.right)
            
        return result