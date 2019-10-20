/* author: Ayan Goel
This algorithm uses stacks to inorder traverse the Binary Tree in Java. 
The following implemention does not require recursion and is better suited but the code is complex. */
import java.util.*;
//create a Node class for tree structure
class Node {
	int info;
	Node left, right;

	public Node(int data) {
		info = data;
		left = right = null;
	}
}
//create a class to for BinaryTree
class BinaryTree {
	Node root;
//function for inorder traversal
	void inorder() {
		//first check the null
		if (root == null) {
			return ;
		}
		//create a stack to store the values
		Stack<Node> stk = new Stack<Node>();
		Node curr = root;
		//run the loop and traverse to the left of the curr until curr is null and size of stack is not empty
		while (curr != null || stk.size() > 0) {
			while (curr != null) {
				stk.push(curr);
				curr = curr.left;
			}
			//after this curr must be null so we pop out element from stack
			curr = stk.pop();
			System.out.print(curr.info + " ");
			//print the data
			//now we have traversed the left sub-tree, now we will traverse the right sub tree
			curr = curr.right;
		}
	}
}

class BinaryTreeInOrderTraversalWithoutRecursion {
	/* create nodes according to this tree structure
	        1
          /   \
        2      3
      /  \
    4     5 */
    public static void main(String[] args) {
    	BinaryTree tree = new BinaryTree();
    	tree.root = new Node(1);
    	tree.root.left = new Node(2);
    	tree.root.right = new Node(3);
    	tree.root.left.left = new Node(4);
    	tree.root.left.right = new Node(5);
    	tree.inorder();
    }
}