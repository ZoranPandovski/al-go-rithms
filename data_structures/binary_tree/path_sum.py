def hasPathSum(self, root: Optional[TreeNode], S: int) -> bool:
    if root == None:
        return False
    if root.right == None and root.left == None:
        return S == root.val
        
    return self.hasPathSum(root.left, S-root.val) or self.hasPathSum(root.right, S-root.val)