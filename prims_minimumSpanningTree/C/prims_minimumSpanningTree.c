/*
Prim's Algorithm Implementation
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define INF 9999999
// Number of vertices in graph
#define V 5

// Create a 2D array of size - 5 x 5
// Adjacency matrix to represent graph
int G[V][V] = {
    {0, 9, 75, 0, 0},
    {9, 0, 95, 19, 42},
    {75, 95, 0, 51, 66},
    {0, 19, 51, 0, 31},
    {0, 42, 66, 31, 0}};

int main() {
    int numOfEdges;  // Number of edges
    
    // Create a array to track selected vertex
    // Selected will become true otherwise false
    int selected[V];
    
    // Set selected false initially
    memset(selected, false, sizeof(selected));
    
    // Set number of edge to 0
    numOfEdges = 0;
    
    // The number of egde in minimum spanning tree will be
    // always less than (V -1), where V is number of vertices in the
    // graph
    
    // Choose '0'th vertex and make it true
    selected[0] = true;
    
    int x;  //  Row number
    int y;  //  Col number
    
    // Print for edge and weight
    printf("Edge : Weight\n");
    
    while (numOfEdges < V - 1) {
        // For every vertex in the set S, find the all adjacent vertices
        // , calculate the distance from the vertex selected at step 1.
        // If the vertex is already in the set S, discard it otherwise
        // choose another vertex nearest to selected vertex at step 1.
        
        int min = INF;
        x = 0;
        y = 0;
        
        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j]) {  // not in selected and there is an edge
                        if (min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        
        printf("%d - %d : %d\n", x, y, G[x][y]);
        selected[y] = true;
        numOfEdges++;
    }
    
    return 0;
}

