public class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode() {}
      TreeNode(int val) { this.val = val; }
      TreeNode(int val, TreeNode left, TreeNode right) {
          this.val = val;
          this.left = left;
           this.right = right;
      }
  }

class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
            
        Queue<TreeNode> q=new LinkedList<TreeNode>();
            List<List<Integer>> r=new ArrayList();
            if(root==null)
                    return r;
            
            q.add(root);
            while(!q.isEmpty())
            {
                    int count=q.size();
                     List<Integer> l=new ArrayList();
                    
                    for(int i=0;i<count;i++)
                    {
                           
                           TreeNode curr=q.poll();
                           l.add(curr.val);
                            if(curr.left!=null)
                            q.add(curr.left);
                            if(curr.right!=null)
                            q.add(curr.right);
                    }
            r.add(l);
            }
     return r;     
    }
}
