
import java.util.Scanner;

//undirectedGraph

public class Main {
	public static void main(String args[]){
		int numberOfNodes=0;
		int numberOfRelations=0;
		int matrix[][];
		int sourceNode=0;
		int targetNode=0;
		Scanner key = new Scanner(System.in);
		System.out.println("Please enter the number of nodes in graph");
		numberOfNodes=key.nextInt();
		System.out.println("Please enter the number of relations between nodes");
	        numberOfRelations = key.nextInt();
		matrix=new int[numberOfNodes][numberOfNodes];
		for(int i = 0;i<numberOfNodes;i++){
			for(int j = 0;j<numberOfNodes;j++){
				matrix[i][j]=0;
			}
		}
		for(int i = 0;i<numberOfRelations;i++){
			sourceNode=key.nextInt();
			targetNode=key.nextInt();
			matrix[sourceNode][targetNode]=1;
			matrix[targetNode][sourceNode]=1;
		}
		
		for(int i = 0;i<numberOfNodes;i++){
			for(int j = 0;j<numberOfNodes;j++){
				System.out.print(matrix[i][j]);
			}
			System.out.println();
		}
		
		Graph graph = new Graph(matrix);
		System.out.println("iterativeDfs");
		graph.iterativeDfs();
		System.out.println("recursiveDfs");
		graph.recursiveDfs(0);


		matrix=new int[][]{
			{0,1,0,0,0,0,1},
			{1,0,1,1,0,0,0},
			{0,1,0,0,0,0,0},
			{0,1,0,0,1,1,0},
			{0,0,0,1,0,0,0},
			{0,0,0,1,0,0,0},
			{1,0,0,0,0,0,0}
		};
		Graph firstTestMatrixGraph = new Graph(matrix);
		System.out.println("firstTestMatrixGraph iterativeDfs");
		firstTestMatrixGraph.iterativeDfs();
		System.out.println("firstTestMatrixGraph recursiveDfs");
		firstTestMatrixGraph.recursiveDfs(0);

		matrix=new int[][]{
			{0,1,1,0},
			{1,0,0,1},
			{1,0,0,0},
			{0,1,0,0}
		};
		Graph secondTestMatrixGraph = new Graph(matrix);
		System.out.println("secondTestMatrixGraph iterativeDfs");
		secondTestMatrixGraph.iterativeDfs();
		System.out.println("secondTestMatrixGraph recursiveDfs");
		secondTestMatrixGraph.recursiveDfs(0);

		
	}
}
