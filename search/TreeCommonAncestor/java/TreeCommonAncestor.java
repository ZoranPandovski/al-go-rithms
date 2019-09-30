/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mypkg;

/**
 *
 * @author Jose
 */
import java.util.ArrayList;
import java.util.List;

class Node {

    String data;
    Node left, right;

    Node(String value) {
        data = value;
        left = right = null;
    }
}

public class exercise15 {

    Node root;
    private List<String> list1 = new ArrayList<>();
    private List<String> list2 = new ArrayList<>();

    String findAncestor(String n1, String n2) {
        list1.clear();
        list2.clear();
        return ancestor(root, n1, n2);
    }

    private String ancestor(Node root, String n1, String n2) {

        if (!findList(root, n1, list1) || !findList(root, n2, list2)) {
            System.out.println((list1.size() > 0) ? "n1 empity" : "n1 empity");
            System.out.println((list2.size() > 0) ? "n2 empity" : "n2 empity");
            //return -1;
            return null;
        }

        int i;
        for (i = 0; i < list1.size() && i < list2.size(); i++) {
            //System.out.println(list1.get(i) + " " + list2.get(i));
            if (!list1.get(i).equals(list2.get(i))) {
                break;
            }
        }

        return list1.get(i - 1);
        //get(i-1);
    }

    private boolean findList(Node root, String var, List<String> list) {
        if (root == null) {
            return false;
        }

        list.add(root.data);

        if (root.data == var) {
            return true;
        }

        if (root.left != null && findList(root.left, var, list)) {
            return true;
        }

        if (root.right != null && findList(root.right, var, list)) {
            return true;
        }

        list.remove(list.size() - 1);

        return false;
    }

    public static void main(String[] args) {
        exercise15 tree = new exercise15();
        tree.root = new Node("A");
        tree.root.left = new Node("B");
        tree.root.right = new Node("G");
        tree.root.right.right = new Node("T");
        tree.root.left.left = new Node("F");
        tree.root.left.right = new Node("V");
        tree.root.left.right.left = new Node("L");
        
        /* Construct the following binary tree
                  A
                /   \
               B     G
              /  \     \
             F    V     T
                 /
                L    
        */
        
        System.out.println("");

        System.out.println("last ancestor in common (F, L): " + tree.findAncestor("F", "L"));
        System.out.println("last ancestor in common (F, T): " + tree.findAncestor("F", "T"));
        System.out.println("last ancestor in common (V, T): " + tree.findAncestor("V", "T"));
    }
}