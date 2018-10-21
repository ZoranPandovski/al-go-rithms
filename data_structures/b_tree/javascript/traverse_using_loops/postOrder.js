/*
Given a binary tree, print its post-order traversal without using recursion.

Case:
                1
	        2		3
        4	   5

Level order traversal: 1, 2, 3, 4, 5
Post-order traversal: 4, 5, 2, 3, 1
*/


/*
    Input: Root element of tree
    Output: An array containing post-order traversal of binary tree
*/
function postorderTraversal(root) {
	if (!root) {
		return [];
	}

	var stack = [root];
	var postOrder = [];
	var visited = new Map();
	var current = null;

	while (stack.length) {
		current = stack.pop()

		if (visited.has(current) === true){
			postOrder.push(current.data)
		} else {
			visited.set(current, true)
			stack.push(current);
			if (current.right) {
				stack.push(current.right);
			}

			if (current.left) {
				stack.push(current.left);
			}
		}
	}

	return postOrder
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

var ans = postorderTraversal(n1);
console.log(ans);
