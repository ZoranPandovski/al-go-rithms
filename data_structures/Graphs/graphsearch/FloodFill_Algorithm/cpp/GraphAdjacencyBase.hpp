#ifndef GRAPH_ADJACENCY_BAG
#define GRAPH_ADJACENCY_BAG 1
/*
 * A base class which can denote any Graph Adjacency representation.
 * Subclasse by AdjacencyMatrix and AdjacencyList
 * Use this class in your graphs to be able to select any representation as desired by the user.
 */
class GraphAdjacencyBase {
	/* Destructor:
	 * releases all resources acquired by the class
	 */
  public:
  	virtual ~GraphAdjacencyBase(){}
	/*
	 * Function: edgeExists
	 * Returns true if an edge exists between vertices i and j, false otherwise.
	 */
  virtual bool edgeExists(int i, int j) = 0;
	/*
	 * Function: vertices
	 * Returns the number of vertices in the adjacency structure.
	 */
  virtual int vertices() = 0;
	/*
	 * Function: edges
	 * Returns the number of edges in the adjacency structure.
	 */
  virtual int edges() = 0;
	/*
	 * Function add:
	 * Adds an edge between vertices i and j
	 */
  virtual void add(int i, int j, int w) = 0;
	/*
	 * Function: remove
	 * Deleted the edge between vertices i and j
	 */
  virtual void remove(int i, int j) = 0;
	/*
	 * Function: degree
	 * Returns the degree of the vertex i
	 */
  //virtual int degree(int i){}

  //virtual int indegree(int i) = 0;
  
  //virtual int outdegree(int i) = 0;

};
#endif /* ifndef GRAPH_ADJACENCY_BAG */