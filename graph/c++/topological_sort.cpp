#include<bits/stdc++.h>
using namespace std;
// Complexity -> O(E+V)
// https://en.wikipedia.org/wiki/Topological_sorting#Kahn's_algorithm


// Contains the resultant topological order in lexicographic order
vector<size_t> topologicalOrder;

// Takes adjacency-list and the in-degree of all the vertices as the input.
// Returns true if no cycle, false otherwise.
// Populates the global variable `topologicalOrder`
bool TopologicalSort( const vector<vector<size_t> >& adjList, vector<size_t>& inDegree )
{
	size_t numberOfVertices = adjList.size();
	topologicalOrder.resize( numberOfVertices, -1 );

	size_t topologicalOrderIt = 0;

	// A min priority-queue; The lowest is at the top
	// A priority queue is required for lexicographic ordering only.
	// We can use a queue if we want any random valid topological order.
	priority_queue<size_t, vector<size_t>, greater<size_t> > pq;

	// The queue contains all the vertices whose inDegree has become zero during the algorithm process
	for ( size_t i = 0; i < numberOfVertices; i++ )
	{
		if ( inDegree[i] == 0 )
		{
			pq.push( i );
		}
	}

	// If there is no cycle, inDegree of every vertex will be 0 by the end of this loop
	while ( !pq.empty() )
	{
		size_t u = pq.top();
		pq.pop();

		const vector<size_t>& neighbours = adjList[u];

		for ( size_t i = 0; i < neighbours.size(); i++ )
		{
			// inDegree of any vertex will not go below 0 during the whole process
			inDegree[neighbours[i]]--;
			if ( inDegree[neighbours[i]] == 0 )
			{
				pq.push( neighbours[i] );
			}
		}

		topologicalOrder[topologicalOrderIt++] = u;
	}

	// True if cycle does not exist
	return topologicalOrderIt == numberOfVertices;
}

void CalculateInDegree( const vector<vector<size_t> >& adjList, vector<size_t>& inDegree )
{
	inDegree.resize( adjList.size() );

	for ( size_t i = 0; i < adjList.size(); i++ )
	{
		for ( size_t j = 0; j < adjList[i].size(); j++ )
		{
			size_t v = adjList[i][j];
			inDegree[v]++;
		}
	}
}

int main()
{
	vector<vector<size_t> > adjList( 6 );

	adjList[2].push_back( 3 );
	adjList[3].push_back( 1 );
	adjList[4].push_back( 0 );
	adjList[4].push_back( 1 );
	adjList[5].push_back( 0 );
	adjList[5].push_back( 2 );

	vector<size_t> inDegree;
	CalculateInDegree( adjList, inDegree );
	TopologicalSort( adjList, inDegree );
	for(size_t i=0;i<topologicalOrder.size();i++)
  {
    cout << topologicalOrder[i] << " ";
  }
}
