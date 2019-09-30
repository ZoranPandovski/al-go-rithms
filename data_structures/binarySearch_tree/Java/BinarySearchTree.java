public class BinarySearchTree {
	private int value;
	private BinarySearchTree left;
	private BinarySearchTree right;

	public BinarySearchTree(int value) {
		this.value = value;
		this.left = null;
		this.right = null;
	}

	public String printInorder(BinarySearchTree root) {
		String result = "";
		
		if(root.left != null) {
			result = result + root.printInorder(root.left);
		}

		result = result + root.value;

		if(root.right != null) {
			result = result + root.printInorder(root.right);
		}

		return result;
	}

	public int height(BinarySearchTree root) {
		if(root == null) {
			return 0;
		}

		int left = 1 + root.height(root.left);
		int right = 1 + root.height(root.right);

		if(left > right) {
			return left;
		} else {
			return right;
		}
	}

	public String printPreorder(BinarySearchTree root) {
		String result = "";
		
		result = result + root.value;
		
		if(root.left != null) {
			result = result + root.printPreorder(root.left);
		}

		if(root.right != null) {
			result = result + root.printPreorder(root.right);
		}

		return result;
	}

	public String printPostorder(BinarySearchTree root) {
		String result = "";
		
		if(root.left != null) {
			result = result + root.printPostorder(root.left);
		}

		if(root.right != null) {
			result = result + root.printPostorder(root.right);
		}

		result = result + root.value;
		
		return result;
	}

	public BinarySearchTree makeNode(int value) {
		BinarySearchTree node = new BinarySearchTree(value);
		return node;
	}

	public int minimum(BinarySearchTree root) {
		if(root != null) {
			while(root.left != null) {
				root = root.left;
			}
			return root.value;
		}
		return -1;
	}

	public BinarySearchTree delete(BinarySearchTree root, int value) {
		if(root == null) {
			return root;
		}

		if(root.value > value) {
			root.left = root.delete(root.left, value);
		} else if(root.value < value) {
			root.right = root.delete(root.right, value);
		} else {
			if(root.left != null && root.right != null) {
				int tmp = root.minimum(root.right);
				root.value = tmp;
				root.right = root.delete(root.right, tmp);
			} else {
				BinarySearchTree tmp = root;
				if(root.left != null) {
					root = root.left;
				} else {
					root = root.right;
				}
			}
		}

		return root;
	}

	public BinarySearchTree addNode(BinarySearchTree root, int value) {
		if(root == null) {
			root = root.makeNode(value);
		} else if(root.value == value) {
			return root;
		} else if(root.value > value) {
			if(root.left == null) {
				root.left = root.makeNode(value);
			} else {
				root.left = root.addNode(root.left, value);
			}
		} else if(root.value < value) {
			if(root.right == null) {
				root.right = root.makeNode(value);
			} else {
				root.right = root.addNode(root.right, value);
			}
		}

		return root;
	}

	public static void main(String []args) {
		BinarySearchTree tree = null;
		tree = new BinarySearchTree(5);
		tree = tree.addNode(tree, 3);
		tree = tree.addNode(tree, 2);
		tree = tree.addNode(tree, 4);
		tree = tree.addNode(tree, 7);
		tree = tree.addNode(tree, 6);
		tree = tree.addNode(tree, 8);

		System.out.println("Inorder: " + tree.printInorder(tree));
		System.out.println("Postorder: " + tree.printPostorder(tree));
		System.out.println("Preorder: " + tree.printPreorder(tree));
		System.out.println("Height: " + tree.height(tree));

		tree = tree.delete(tree, 5);

		System.out.println("Inorder: " + tree.printInorder(tree));
	}
}
