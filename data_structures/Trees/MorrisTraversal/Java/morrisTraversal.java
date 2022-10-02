import java.util.*;

public class morrisTraversal {

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.left = new TreeNode(6);
        root.right.left.right = new TreeNode(7);
        root.right.left.right.right = new TreeNode(8);

        System.out.println("Morris Inorder" + getInorder(root));
 
    }

    public static ArrayList<Integer> getInorder(TreeNode root) {

        ArrayList<Integer> inorder = new ArrayList<Integer>();
        if (root == null) return inorder;

        TreeNode curr = root;
        while (curr != null) {
            if (curr.left == null) {
                inorder.add(curr.val);
                curr = curr.right;
            } else {
                TreeNode prev = curr.left;
                while (prev.right != null && prev.right != curr) {
                    prev = prev.right;
                }
                if (prev.right == null) {
                    prev.right = curr;
                    curr = curr.left;
                } else {
                    prev.right = null;
                    inorder.add(prev.val);
                    curr = curr.right;
                }
            }
        }
        return inorder;
    }
}
