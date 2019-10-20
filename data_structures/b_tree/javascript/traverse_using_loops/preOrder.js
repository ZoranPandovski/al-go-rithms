/*
Given a binary tree, print its pre-order traversal without using recursion.

Case:
                1
	        2		3
        4	   5

Level order traversal: 1, 2, 3, 4, 5
Pre-order traversal: 1, 2, 4, 5, 3

*/


/*
    Input: Root element of tree
    Output: An array containing pre-order traversal of binary tree
*/
function preorderTraversal(A) {
	var stack = [];
	var preOrder = [];
	if (!A) {
		return preOrder;
	}

	var current = A;
	while (current || stack.length) {
		if (current) {
			preOrder.push(current.data);
			if (current.right) {
				stack.push(current.right);
			}
			current = current.left;
		} else {
			current = stack.pop();
			preOrder.push(current.data);
			current = current.left;
		}
	}

	return preOrder;
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

var ans = preorderTraversal(n1);
console.log(ans);
