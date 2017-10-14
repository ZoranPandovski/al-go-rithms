/* 
 * Time-Complexity:- O(V+E)
 * 
 */


import java.util.*;

public class BFS {

	static ArrayList<ArrayList<Integer>> graph;
	static Queue<Integer> queue;
	public static void traverse(int source)
	{
		queue = new LinkedList<>();
		queue.add(source);
		boolean[] visited = new boolean[graph.size()];
		visited[source]=true;
		while(!queue.isEmpty())
		{
			int q = queue.poll();
			System.out.println(q);
			ArrayList<Integer> list = graph.get(q);
			for(int i=0;i<list.size();i++)
			{
				if(!visited[list.get(i)])
				{
					queue.add(list.get(i));
					visited[list.get(i)] = true;
				}
			}
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		graph = new ArrayList<>();
		Scanner sc = new Scanner(System.in);
		int vertices = sc.nextInt();
		int edges = sc.nextInt();
		for(int i=0;i<vertices;i++)
			graph.add(new ArrayList<>());
		for(int i=0;i<edges;i++)
		{
			int u = sc.nextInt();
			int v = sc.nextInt();
			graph.get(u-1).add(v-1);
			graph.get(v-1).add(u-1);
		}
		int source = sc.nextInt();
		traverse(source-1);
		sc.close();
	}
}
