import java.util.*;

public class depthFirstSearch
{
    int Vertices;

    LinkedList<Integer> adjList[];

    depthFirstSearch(int vertices)
    {
        Vertices = vertices;
        adjList = new LinkedList[vertices];
        for (int i=0; i<vertices; ++i)
        {
            adjList[i] = new LinkedList();
        }
    }
    void addEdges(int vertices, int u)
    {
        adjList[vertices].add(u);
    }

    void DFTraversal(int vertices,int visited[])
    {
        visited[vertices] = 1;
        System.out.print(vertices + " ");
        Iterator<Integer> i = adjList[vertices].listIterator();
        while (i.hasNext())
        {
            int n = i.next();
            if (visited[n]==0)
                DFTraversal(n, visited);
        }
    }

    void DFSearch(int vertices)
    {

        int visited[] = new int[Vertices];

        DFTraversal(vertices, visited);
        for (int i=1;i<Vertices;i++)
        {
            if(visited[i]==0)
            {
                DFTraversal(i, visited);
            }
        }
    }
}
