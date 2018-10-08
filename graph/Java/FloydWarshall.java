/* Floyd Warshall's algorithm is an all pair shortest path algorithm which finds 
 * shortest path between each pair of vetices in O(V^3) time complexity, where
 * V is the number of vertices in the graph. In this implementation matrix representation
 * of graph is used.
 */
public class FloydWarshall {
    public final static int INFINITE = 100000;
    public int[][] floydWarshall(int graph[][]) {
	int size = graph.length;
	int distance[][] = new int[size][size];
	int i,j,k;

	for(i=0;i<size;i++) {
	    for(j=0;j<size;j++) {
		distance[i][j] = graph[i][j];
	    }
	}

	for(k=0;k<size;k++) {
	    for(i=0;i<size;i++) {
		for(j=0;j<size;j++) {
		    // If vertex k provides shortest path from i to j then update distance through i to k and k to j
		    if(distance[i][k]+distance[k][j]<distance[i][j]) {
			distance[i][j] = distance[i][k]+distance[k][j];
		    }
		}
	    }
	}
	return distance;
    }
    public static void main(String args[]) {
	int graph[][] = {{0,2,INFINITE,10,1},
			 {INFINITE,0,4,INFINITE,INFINITE},
			 {INFINITE,INFINITE,0,INFINITE,INFINITE},
			 {2,INFINITE,1,0,INFINITE},
			 {INFINITE,INFINITE,3,INFINITE,0}};
	int dist[][] = new FloydWarshall().floydWarshall(graph);
	for(int i=0;i<5;i++) {
	    for(int j=0;j<5;j++) {
		System.out.print((dist[i][j]==INFINITE?"INF":(dist[i][j]+""))+"\t");
	    }
	    System.out.println();
	}
    }
}
