function TreeNode(data) {
	this.data = data;
	this.left = null;
	this.right = null;
}

/*
Create this tree and return its root

                1
	        2		3
        4	   5|6		7
*/


module.exports = function() {
    var n1 = new TreeNode(1)
    var n2= new TreeNode(2)
    var n3 = new TreeNode(3)
    var n4 = new TreeNode(4)
    var n5 = new TreeNode(5)
    var n6 = new TreeNode(6)
    var n7 = new TreeNode(7)

    n1.left = n2
    n1.right = n3

    n2.left = n4
    n2.right = n5

    n3.left = n6
    n3.right = n7

    var root = n1
    return root
}
