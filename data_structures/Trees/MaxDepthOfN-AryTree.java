/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val,List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    public int maxDepth(Node root) {
        
        if(root==null) return 0;
        
        if(root.children == null || root.children.isEmpty()) return 1;
        
        int maxDepth = 0;
        
        for(Node node : root.children){
            int childDepth = maxDepth(node);
            if(childDepth > maxDepth) maxDepth = childDepth;

        }
        
        return 1 + maxDepth;
        
    }
}
