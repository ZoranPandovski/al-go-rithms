#include<iostream>
#include <list>
 
using namespace std;
 int edgevisit[100][100];
 int colorarray[100];
 
 void initialise()
 {
 	for(int i=0;i<100;i++)
    {colorarray[i]=-1;
    	for(int j=0;j<100;j++)
    	{
    	edgevisit[i][j]=-1;
    	
    	}
    }
    
 }
class Graph
{
    int V;    // No. of vertices
 
   
    list<int> *adj;
    int *distance;
    int *visited;
	   
public:
    Graph(int V);  // Constructor
 
 
    // function to add an edge to graph
    void addEdge(int v, int w); 
 
    // prints BFS traversal from a given source s
    void BFS(int s);
	
	void classification();
	void connected();  
	void bipartite();
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    distance= new int[V];
    visited= new int[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to vâ€™s list.
	edgevisit[v][w]=1;
}
 
void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
//int *distance= new int[V];
  //  bool *visited = new bool[V];
    
    
    for(int i = 0; i < V; i++)
        {
        visited[i] = false;
 		distance[i]=0;
 		}
    // Create a queue for BFS
    list<int> queue;
 
 
    visited[s] = true;
    queue.push_back(s);
 
    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;
 colorarray[s]=0;
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
 		
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {   
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
               distance[*i]=distance[s]+1;
               edgevisit[s][*i]=0; 
               if(colorarray[s]==0)
               colorarray[*i]=1;
               else if(colorarray[s]==1)
               colorarray[*i]=0;
               else 
			   continue;
            }
            
        }
    }
}
	//Classification of Edges
	
 void Graph::classification()
{	 	
	for(int i=0;i<V;i++)
    {
    for(int j=i;j<V;j++)
    {
    if(edgevisit[i][j]==1)
    {
    if(distance[i]==distance[j])
    edgevisit[i][j]=2;
    
    else 
    continue;
    }
    }
    }
    cout<<endl;
    for(int i=0;i<V;i++)
    {
   	for(int j=i;j<V;j++)
   	{
   	if(edgevisit[i][j]==0)
   	cout<<i<<"--"<<j<<" is a tree edge"<<endl;
   	if(edgevisit[i][j]==1)
   	cout<<i<<"--"<<j<<" is a VCE edge"<<endl; 
   	 if(edgevisit[i][j]==2)
   	cout<<i<<"--"<<j<<" is a HCE edge"<<endl;
  }
  }
}
//Checking if the graph is connected or not.
void Graph::connected()
 {
 
  int c = 0;
    for(int i=0;i<V;i++)
  {
  	if(visited[i]!=true)
  	{
	  cout<<"the graph is disconnected"<<endl;
	  c = 1;
 	  break;
	}

	} 
	if (c == 0)
	   cout  <<"the graph is connected"<<endl;

}
//Bipartite graph
void Graph::bipartite()
{ 
list<int>::iterator i;
int k=0;
  for(int j=0;j<V;j++)
  {
  for(i=adj[j].begin();i!=adj[j].end();++i)
  {
  if(colorarray[j]==colorarray[*i])
  {
  	cout<<"graph is not bipartite"<<endl;
	 k=1;
	  break;
	}	
}
  }
if(k==0)
{
cout<<"the graph is bipartite"<<endl;	
}
}



int main()
{
   initialise();
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0 ,3);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    //g.addEdge(2, 4);
 	//g.addEdge(4,5);
 	//g.addEdge(6,7);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 0) \n";
    g.BFS(0);
g.classification();
g.connected();
g.bipartite();
    return 0;

}
