import java.util.*;
import java.io.*;

public class ERDC {
	
	public static TreeSet<Integer> adj[];
	public static int[] parent;
	public static int[] dist;
	public static boolean[] visited;
	
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		System.out.println("Enter The number of vertex: ");
		int v = in.nextInt();
		System.out.println("Enter the number of edges: ");
		int e = in.nextInt();
		int radius=Integer.MAX_VALUE,diameter=Integer.MIN_VALUE;
		
		
		adj = new TreeSet[v+1];
		parent = new int[v+1];
		dist = new int[v+1];
		visited = new boolean[v+1];
		
		for(int i=0;i<=v;i++)
			adj[i] = new TreeSet<Integer>();
		
		System.out.println("Enter the graph: ");
		for(int i=0;i<e;i++)
		{
			int x = in.nextInt();
			int y = in.nextInt();
			
			adj[x].add(y);
			adj[y].add(x);
		}
		
		for(int i=1;i<=v;i++)
		{
			System.out.println("Eccentricity of "+i+" is: "+BFS(i,v));
			radius=Math.min(radius, BFS(i,v));
			diameter=Math.max(diameter, BFS(i,v));
		}
		System.out.println();
		System.out.println("Radius of graph is: "+radius);
		System.out.println("Diameter of graph is: "+diameter);
		System.out.println();
		
		for(int i=1;i<=v;i++)
		{
			if(BFS(i,v)==radius)
				System.out.println("Centre of graph is: "+i);
		}
			
	
			
	}
	public static int BFS(int s,int ver)
	{
		int max=Integer.MIN_VALUE;
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(s);
		parent[s]=0;
		dist[s]=0;
		visited[s]=true;
		for(int i=1;i<=ver;i++)
		{
			if(i!=s)
				visited[i]=false;
		}
		
		while(!q.isEmpty())
		{
			int v = q.poll();
			for(int u : adj[v])
			{
				if(!visited[u])
				{
					parent[u]=v;
					dist[u]=dist[v]+1;
					visited[u]=true;
					q.add(u);
				}
				max=Math.max(max, dist[u]);
				
			}
		}
		return max;
	}
}
