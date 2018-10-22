import java.util.*;

class Hamiltonian{
	/*
		adj[0:n-1, 0:n-1] is the graph adjacency matrix
		x[1:n] saves path during execution
		n is the no. of nodes in the graph.
	*/
	private int adj[][], x[],n;
	private static boolean f=true;

	public void takeInput() {
		Scanner src = new Scanner(System.in);
		System.out.println("Enter the number of nodes");
		n = src.nextInt();
		x = new int[n];
		x[0] = 0;

		for(int i=1; i<n; i++)
		   x[i] = -1;

		adj = new int[n][n];

		System.out.println("Enter the adjacency matrix");

		for(int i=0; i<n; i++)
		  for(int j=0; j<n; j++)
		 	adj[i][j] = src.nextInt();
	}

	/*
		x[1:k-1] is a path of k-1 distinct vertices. If x[k] = 0, then
		no vertex has yet been assigned to x[k]. After execution, x[k]
		is assigned to the next highest numbered vertex which does not
		already appear in x[1:k-1] and is connected by an edge to
		x[k]. Otherwise x[k] = 0. If k = n, then in addition x[k] is
		connected to x[1].
	*/
	public void nextValue(int k){
		int i=0;
		while(true){
			x[k] = x[k] + 1;
			if(x[k] == n)	x[k] = -1;
			if(x[k] == -1)	return;
			if( adj[x[k-1]][x[k]] == 1){
				for( i=0; i<k; i++){
					if(x[i] == x[k])	break;
				}
				if(i == k){
					if( k<n-1 || k == n-1 && adj[x[n-1]][0] == 1)	return;
				}
			}
		}
	}

	/*
		This algorithm uses the recursive formulation of backtracking
		to find all the hamiltonian cycles of a graph. The graph is
		stored as an adjacency matrix G[1:n, 1:n]. All cycles begin
		at node 1.
	*/
	public void hamiltonian( int k){
		while(true){
			nextValue(k);
			if(x[k] == -1)	return;
			if( k == n-1){
				System.out.println("\nSolution: ");
				for( int i=0; i<n; i++)
					System.out.print((x[i]+1) + "  ");

				System.out.println();
				f = false;
			}
			else
				hamiltonian(k+1);
		}
	}


	public static void main( String[] args){
		Hamiltonian obj = new Hamiltonian();
		obj.takeInput();
		obj.hamiltonian(1);
		if(f)
			System.out.println("\nNo Solution Exist");
	}
}

/* Test Cases
Input:
5
0 1 0 1 0
1 0 1 1 1
0 1 0 0 1
1 1 0 0 1
0 1 1 1 0

Output:
1  2  3  5  4  
1  4  5  3  2  


Input:
5
0 1 0 1 0
1 0 1 1 1
0 1 0 0 1
1 1 0 0 0
0 1 1 0 0

Output:
No solution exist
*/
