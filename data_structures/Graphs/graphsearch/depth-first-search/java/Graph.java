import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class Graph {

	int[][] adjacencyMatrix;
	int rootNode = 0;
	int numberOfNodes = 0;

	boolean[] visitedNodes;

	public Graph(int[][] matrix) {
		int i = 0;
		int j = 0;

		numberOfNodes = matrix.length;
		adjacencyMatrix = new int[numberOfNodes][numberOfNodes];

		for (i = 0; i < numberOfNodes; i++) {
			for (j = 0; j < numberOfNodes; j++) {
				adjacencyMatrix[i][j] = matrix[i][j];
			}
		}

		visitedNodes = new boolean[numberOfNodes];
	}

	public void bfs() {

		Queue<Integer> queue = new LinkedList<Integer>();

		queue.add(rootNode);
		visitedNodes[rootNode] = true;

		makeOperationWithNode(rootNode);
		while (!queue.isEmpty()) {
			int n, child;

			n = (queue.peek()).intValue();

			child = getUnvisitedChildNode(n);

			if (child != -1) {
				visitedNodes[child] = true;
				makeOperationWithNode(child);

				queue.add(child);
			} else {
				queue.remove();
			}
		}

		for (int i = 0; i < visitedNodes.length; i++)
			visitedNodes[i] = false;
	}
	
	public void iterativeDfs() {

		Stack<Integer> stack = new Stack<Integer>();

		stack.push(rootNode);

		while (!stack.isEmpty()) {
			int n;
			n = stack.pop();
			
			if (!visitedNodes[n]) {
				visitedNodes[n] = true;
				makeOperationWithNode(n);
				for (int i = numberOfNodes-1; i >=0; i--) {
					if (adjacencyMatrix[n][i] > 0){
				//		System.out.println(i + " is pushed to the stack");
						stack.push(i);
					}
				}
			} 
		}
		System.out.println("dfs is done");
		for (int i = 0; i < visitedNodes.length; i++)
			visitedNodes[i] = false;
	}
	
	public void recursiveDfs(int rootNode){
		visitedNodes[rootNode] = true;
		makeOperationWithNode(rootNode);

		for (int i = 0; i < numberOfNodes ; i++) {
			if (adjacencyMatrix[rootNode][i] > 0 && !visitedNodes[i]){
				recursiveDfs(i);
			}
		}
		
	}

	int getUnvisitedChildNode(int n) {

		for (int i = 0; i < numberOfNodes; i++) {
			if (adjacencyMatrix[n][i] > 0 && !visitedNodes[i])
				return (i);
		}
		return (-1);
	}

	void makeOperationWithNode(int nodeIndex) {
		System.out.println(nodeIndex);

	}

}
