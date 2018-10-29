import java.util.ArrayList;

/**
 * @author avcbcoder last modified @29-Oct-2018 @11:29:01 PM Code Library - TODO
 */

/**
 * <========================================= Sorting using 0-1 tree =============================================>
 * 
 * DESCRIPTION of all the methods in stack class --------------------------------------------------------------------
 * 
 * sort_bts() function sort all the integers using 0-1 tree
 * 
 */

/** 
 */
public class BIT_Tree_Sort {
	public static void main(String[] args) throws Exception {
		ArrayList<Long> al = sort_bts(new long[] {  9L, 10L, 56L, 34L, 22L });
		System.out.println("Sorted=>" + al); // sorted output
	}

	/**
	 * This function just takes an array that need to be sorted and returns a
	 * sorted arraylist
	 */
	public static ArrayList<Long> sort_bts(long[] arr) {
		ArrayList<Long> ans = new ArrayList<>();
		BIT_Tree_Sort bts = new BIT_Tree_Sort(32);
		for (int i = 0; i < arr.length; i++)
			bts.insert(arr[i]);
		bts.printAllNums(bts.root, 0, 0, ans);
		return ans;
	}

	public int maxBit;
	public Node root;
	public long pow[];

	public class Node {
		boolean bit, end;
		Node left, right;// children nodes
	}

	public BIT_Tree_Sort(int maxBit) {
		this.maxBit = maxBit;
		this.root = new Node();
		pow = new long[maxBit];
		pow[0] = 1;
		for (int i = 1; i < pow.length; i++)
			pow[i] = pow[i - 1] * 2;
	}

	// 31st bit is at 0th position in string-form
	public void insert(long x) {
		String bin = Long.toBinaryString(x);
		StringBuilder sb = new StringBuilder("");
		for (int i = 0; i < maxBit - bin.length(); i++)
			sb.append(0);
		sb.append(bin);
		this.insert(sb.toString(), 0, this.root);
	}

	private void insert(String bin, int idx, Node node) {
		if (idx >= bin.length()) 
			return;

		boolean bit = bin.charAt(idx) - '0' == 0 ? false : true;

		if (!bit) {// left node
			if (node.left == null)
				node.left = new Node();
			node.left.bit = false;
			insert(bin, idx + 1, node.left);
		} else {
			if (node.right == null)
				node.right = new Node();
			node.right.bit = true;
			insert(bin, idx + 1, node.right);
		}
	}

	public void printAllNums(Node node, long x, int level, ArrayList<Long> al) {
		if (node.left == null && node.right == null)
			al.add(x);
		if (node.left != null)
			printAllNums(node.left, x, level + 1, al);
		if (node.right != null)
			printAllNums(node.right, x + pow[maxBit - (level + 1)], level + 1, al);
	}

}
