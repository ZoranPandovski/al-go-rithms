"""
To find whether a tree has a sum of tree from root to leaf is equal to the given number.
If true, return the path which produces the sum. Else, return False
"""
import binary_search_tree

class SumRootLeaf():

    def root_leaf(self,root, given_sum, val, path_list):

        if root == None:
            return

        if root.left == None and root.right == None:
            if (val + root.val) == given_sum:
                path.append(root.val)
                return True
            else:
                return False

        if(self.root_leaf(root.left,given_sum,(val + root.val),path_list)):
            path.append(root.val)
            return True
        if(self.root_leaf(root.right,given_sum,(val + root.val),path_list)):
            path.append(root.val)
            return True

        return False


                                ### Testcases ###

root = None
tree = binary_search_tree.Tree()
root = tree.insert(root, 4)
root = tree.insert(root, 2)
root = tree.insert(root, 1)
root = tree.insert(root, 3)
root = tree.insert(root, 5)

#tree.preorder(root)

obj = SumRootLeaf()
path = []
if(obj.root_leaf(root,9,0,path)):
    print path
else:
    print None
