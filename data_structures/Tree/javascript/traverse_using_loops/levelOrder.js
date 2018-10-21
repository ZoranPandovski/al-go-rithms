/*
Given a binary tree, print its level-order traversal without using recursion.

Case:
                1
	        2		3
        4	   5

Level order traversal: 1, 2, 3, 4, 5
*/


/*
    Input: Root element of tree
    Output: An array containing level-order traversal of binary tree
*/
function levelorderTraversal(root) {
	var stack = [root];
	var levelOrder = [];

	if (root == null) {
		return levelOrder;
	}

	var current = null;

	while (stack.length) {
		current = stack.shift(0);
		if (current) {
			levelOrder.push(current.data);
			if (current.left) {
				stack.push(current.left);
			}

			if (current.right) {
				stack.push(current.right);
			}
		}
	}

	return levelOrder;
}

function TreeNode(data) {
	this.data = data;
	this.left = null;
	this.right = null;
}

var n1 = new TreeNode(1);
var n2 = new TreeNode(2);
var n3 = new TreeNode(3);
var n4 = new TreeNode(4);
var n5 = new TreeNode(5);

n1.left = n2;
n1.right = n3;
n2.left = n4;
n2.right = n5;

var ans = levelorderTraversal(n1);
console.log(ans);