/*
Given a binary tree, print the vertical traversal.

Case 1
                1
	        2		3
        4	   5|6		7

Level order traversal: 1, 2, 3, 4, 5, 6, 7
Top view of tree: 4, 2, 1, 5, 6, 3, 7



Logic: Do a level order traversal and keep a map of nodes on X axis
Maintain a simple map like map = { 
    '0' : [1, 5, 6],
    '-1': [2],
    '+1': [3],
    '-2': [4],
    ....
 }
*/


/*
    Input: Root element of tree
    Output: An array containing the top view starting from leftmost to the rightmost element
*/
function verticalTraverse(root) {
	if (root == null) {
		return [];
	}

	var hash = {};
	var q = [{ node: root, xAxis: 0 }];
	var element;
	var minX = 0,
		maxX = 0;

	while (q.length) {
		element = q.shift();
		node = element.node;
		xAxis = element.xAxis;

		if (hash[xAxis.toString()]) {
			hash[xAxis.toString()].push(node.data);
		} else {
			hash[xAxis.toString()] = [node.data];
		}

		if (node.left) {
			q.push({ node: node.left, xAxis: xAxis - 1 });
			minX = minX > xAxis - 1 ? xAxis - 1 : minX;
		}

		if (node.right) {
			q.push({ node: node.right, xAxis: xAxis + 1 });
			maxX = maxX < xAxis + 1 ? xAxis + 1 : maxX;
		}
	}

	var verticalorder = [];
	for (var i = minX; i <= maxX; i++) {
		var horizontalDistance = i.toString();
		verticalorder.push(hash[horizontalDistance]);
	}

	return verticalorder;
}