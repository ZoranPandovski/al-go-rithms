/*
Given a binary tree, print its in-order traversal without using recursion.

Case:
                1
	        2		3
        4	   5

Level order traversal: 1, 2, 3, 4, 5
In-order traversal: 4, 2, 5, 1, 3

*/


/*
    Input: Root element of tree
    Output: An array containing in-order traversal of binary tree
*/
function inorderTraversal(A) {
	var stack = [];
	var inOrder = [];

	if (A == null) {
		return inOrder;
	}

	var current = A;

	while (current != null || stack.length) {
		if (current) {
			stack.push(current);
			current = current.left;
		} else {
			current = stack.pop();
			inOrder.push(current.data);
			current = current.right;
		}
	}

	return inOrder;
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

var ans = inorderTraversal(n1);
console.log(ans);
