import java.util.*;
 
public class Kosaraju
{
    public void DFS(List<Integer>[] graph, int v, boolean[] visited, List<Integer> comp) 
    {
        visited[v] = true;
        for (int i = 0; i < graph[v].size(); i++)
            if (!visited[graph[v].get(i)])
                DFS(graph, graph[v].get(i), visited, comp);
        comp.add(v);
    }
    public List<Integer> fillOrder(List<Integer>[] graph, boolean[] visited) 
    {        
        int V = graph.length;
        List<Integer> order = new ArrayList<Integer>();
 
        for (int i = 0; i < V; i++)
            if (!visited[i])
                DFS(graph, i, visited, order);
        return order;
    }
    public List<Integer>[] getTranspose(List<Integer>[] graph)
    {
        int V = graph.length;
        List<Integer>[] g = new List[V];
        for (int i = 0; i < V; i++)
            g[i] = new ArrayList<Integer>();
        for (int v = 0; v < V; v++)
            for (int i = 0; i < graph[v].size(); i++)
                g[graph[v].get(i)].add(v);
        return g;
    }
    public List<List<Integer>> getSCComponents(List<Integer>[] graph)
    {
        int V = graph.length;
        boolean[] visited = new boolean[V];
        List<Integer> order = fillOrder(graph, visited);       
        List<Integer>[] reverseGraph = getTranspose(graph);        
        visited = new boolean[V];
        Collections.reverse(order);
 
        List<List<Integer>> SCComp = new ArrayList<>();
        for (int i = 0; i < order.size(); i++)
        {
            int v = order.get(i);
            if (!visited[v]) 
            {
                List<Integer> comp = new ArrayList<>();
                DFS(reverseGraph, v, visited, comp);
                SCComp.add(comp);
            }
        }
        return SCComp;
    }
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        System.out.println("Kosaraju algorithm Test\n");
        Kosaraju k = new Kosaraju();
 
        System.out.println("Enter number of Vertices");
        int V = scan.nextInt();
        List<Integer>[] g = new List[V];
        for (int i = 0; i < V; i++)
            g[i] = new ArrayList<Integer>();
 
        System.out.println("\nEnter number of edges");
        int E = scan.nextInt();
        System.out.println("Enter "+ E +" x, y coordinates");
        for (int i = 0; i < E; i++)
        {
            int x = scan.nextInt();
            int y = scan.nextInt();
            g[x].add(y);
        }
        System.out.println("\nSCC : ");
        List<List<Integer>> scComponents = k.getSCComponents(g);
        System.out.println(scComponents);    
    }    
}
