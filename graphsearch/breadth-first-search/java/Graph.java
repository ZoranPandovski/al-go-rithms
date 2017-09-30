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
