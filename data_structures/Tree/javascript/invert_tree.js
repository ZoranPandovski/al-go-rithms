/*
Given a binary tree, return an inverted binary tree.

Case 1
                1
	        2		3
        4	   5|6		7

Becomes

                1
	        3		2
        7	   6|5		4

*/


/*
    Input: Root element of tree
    Output: Root of inverted binary tree
*/
function invertTree(node) {
	var root = node;
	if (node !== null) {
		var temp = node.left;
		node.left = node.right;
		node.right = temp;
		node.left = invertTree(node.left);
		right = invertTree(node.right);
	}
	return root;
}