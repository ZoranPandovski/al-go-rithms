//We are going to implement Level Order Spiral form traversal in Binary Tree
//using two stacks to maintain a level every time and print it's elements

//create a Node class for storing tree structure
import java.util.Stack;

class Node {
	int info;
	Node left, right;

	public Node(int data) {
		info = data;
		left = right = null;
	}
}

//Create a BinaryTree
class BinaryTree {
	static Node root;

	void printLevelSpiral(Node node) {
		//check for null
		if (node == null) {
			return ;
		}
		
		//create two stacks for implementation
		Stack<Node> stk1 = new Stack<Node>();
		Stack<Node> stk2 = new Stack<Node>();
		
		stk1.push(node); //add the Level 1 in first stack
		
		//traverse till any of the stacks have elements
		while(!stk1.empty() || !stk2.empty()) {
			//print first stack and push the elements into another stack
			while (!stk1.empty()) {
				Node temp = stk1.peek();
				stk1.pop();
				System.out.print(temp.info + " ");
				//push the elements of the next level into the other stack
				if (temp.right != null) {
					stk2.push(temp.right);
				}
				if (temp.left != null) {
					stk2.push(temp.left);
				} 
			}
			//do the same as above for another stack
			while (!stk2.empty()) {
				Node temp = stk2.peek();
				stk2.pop();
				System.out.print(temp.info + " ");
				if (temp.left != null) {
					stk1.push(temp.left);
				}
				if (temp.right != null) {
					stk1.push(temp.right);
				}
			}
		}
	}
}

/* Tree to implement
		 1
  	   /   \
 	  2     3
 	 / \   /  \
	7 	6  5   4
*/

class BinaryTreeLevelOrderSpiralFormIterative {
	public static void main(String[] args) {
		BinaryTree tree = new BinaryTree();
		tree.root = new Node(1);
		tree.root.left = new Node(2);
		tree.root.right = new Node(3);
		tree.root.right.right = new Node(4);
		tree.root.right.left = new Node(5);
		tree.root.left.right = new Node(6);
		tree.root.left.left = new Node(7);
		System.out.println("Spiral Order in Level Order");
		tree.printLevelSpiral(tree.root);
	}
}