// Quesstion Link: https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1/

/**
 * @param {Node} root
 * @returns {number}
 */

/*
class Node{
    constructor(data){
        this.data = data;
        this.left = null;
        this.right = null;
    }
}
*/

class Solution {
  depth(root) {
    if (!root) return 0;
    return 1 + Math.max(this.depth(root.left), this.depth(root.right));
  }
  diameter(root) {
    if (!root) return 0;
    if (!root.left && !root.right) return 1;
    return Math.max(
      1 + this.depth(root.left) + this.depth(root.right),
      this.diameter(root.left),
      this.diameter(root.right)
    );
  }
}
