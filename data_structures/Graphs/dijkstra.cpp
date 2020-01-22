// Program to find Dijkstra's shortest path using STL set
// only uses a Set and does all the operations in that set only hence there is no need of a seperate distance vector
#include <iostream>
#include <bits/stdc++.h>
#define INF INT_MAX          // Max Integer - to display Infinity
using namespace std;

// This class represents a directed graph using  
// adjacency list representation
class Graph
{	// No of Vertices
int nv;        
// Adjacency List
list <pair<int,int>> *adj;    

// set of final Distances of each vertex from the source
/* <distance, vertex> so that the set can sortest by distance of each vertex 
as set of a pair is sorted on the first of the pair */
set<pair<int,int>> set_dist;  

// a List to tell which all vertices visited in the process so that we dont use them in calculating the distance
list<int> visited;  

public:
Graph(int nv) //constructor
{  
	this -> nv = nv;
	adj = new list<pair<int,int>> [nv];
	
}

// function to add an edge to graph
void addEdge(int u, int v, int w) 
{
	adj[u].push_back(make_pair(v,w));
	adj[v].push_back(make_pair(u,w));
}

// function to update the weight of a vertex in the final distance set (set_dist)
// (new weight, vertex)
void chg_wt(int wt, int vertex)
{
	for(auto i = set_dist.begin() ; i != set_dist.end(); ++i)
		if ((*i).second == vertex)  // match the vertex in the set with the given vertex
		{
			// As we cannot directly update the pair in the set, 
			//erase this and add new pair with same vertex but new weight 
			set_dist.erase(i);  
			set_dist.insert(make_pair(wt, vertex));
			break;
		}
}

// function to return the weight of the vertex 
int get_wt(int vertex)
{
	for(auto i = set_dist.begin() ; i != set_dist.end(); ++i)
		if ((*i).second == vertex)
			return (*i).first;                // Return current final weight

	return INF; // if the vertex is not found  return infinity
}

/*function to choose the vertex with min. weight from the Final Set of Distances (set_dist).
Traverse from the begin. of the set and choose a vertex.
 if that vertex is not in the visited vector that means it is not visited yet so choose that vertex and return it 
 as it will be having minimum weight because in the set all vectors are sorted acc. weight */
int get_minwt()
{
	int vtx;
	for(auto i = set_dist.begin(); i != set_dist.end(); i++)
	{
		vtx = (*i).second;
		auto j = find(visited.begin(),visited.end(), vtx); // traverse the visited vector till the end
		if (j == visited.end()) // if the iterator goes to the end then it means the vertex is not present
		{
			return vtx; // return that vertex
		}
	}
	return -1; // vertex is found return a non-positive integer to display error
}


void shortestpath(int src)
{
	int u;  // ( u -> v ) u is initial vertex, v is final vertex

	for(int i = 0; i < nv; i++)
		set_dist.insert(make_pair(INF,i));   // initialize all vertices in the set to INF
	
	u = src; // intially u is the source vertex
	chg_wt(0,src);    // Update src val in set from infinity to zero
	visited.push_back(src);   // update visited vector by adding the source vertex

	while(visited.size() < nv) // check till all vertices are visited
	{		
		// search for the all vertices connected to vertex u in the adjacency list
	for(auto i = adj[u].begin(); i != adj[u].end(); ++i)
	{
		int v = (*i).first;
		auto t = find(visited.begin(), visited.end(), v); // check if v is visited or not
		
		if (t == visited.end()) 			// vertex is not found in the visited vector
		{	
			int weight = (*i).second; // distance between u and v ( u --dist--> v)
			int cwt_u = get_wt(u);   // get current weight of u 
			int cwt_v = get_wt(v);   // get current weight of v
			
			// Relaxation of the vertices v connected to u
			if (cwt_u + weight < cwt_v)  
				chg_wt((cwt_u + weight),v); // update the wt in the main set only
		}
	}
		// get next 'u' by selecting vertex with min. weight 
		u = get_minwt();
		// add new 'u' in the visited vector
		visited.push_back(u);
	}

}
// show values of the distances with the vertices finally obtained
void show()

{	
 	int tp;
 	pair<int,int> temp; //temporary pair for swapping v1 & v2 in <v1,v2>
 	set<pair<int,int>> FINAL;  // copy pairs from set_dist to Final Set
 	
	// swap first and second values of the set to now sort out by vetices
	 for(auto i =  set_dist.begin(); i != set_dist.end(); i++)
	{
		 temp = *i;
		 tp = (temp).first;
		(temp).first = (temp).second;
		(temp).second = tp;		
		FINAL.insert(temp);
	 }
	 // printing values
	 	cout<<" Vertex"<<"			"<<"Distance From Source"<<endl;
	 for(auto i = FINAL.begin(); i != FINAL.end(); i++)
	cout<<"   "<<(*i).first<<"	      		         "<<(*i).second<<endl;
}


};


int main()
{

	int V = 9; 
    Graph g(V); 
  
    //  making above shown graph 
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
  
    g.shortestpath(0); 
  	cout<<"-------------------------------------"<<endl;
  	cout<<"       Dijkstra's Algorithm"<<endl;
  	cout<<"-------------------------------------"<<endl<<endl;
  	g.show();
    
	
	return 0; 

	
}
// Created by Himanshu Gullaiya
