public class Node {

  int data;
  Node left;
  Node right;
  
  void preOrder(Node root) {
      if(root != null){
          System.out.print(root.data + " ");
          preOrder(root.left);          
          preOrder(root.right);
      }
  }
}
