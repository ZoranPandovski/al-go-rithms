/*Johnson's algorithm is a way to find the shortest paths between all pairs of 
vertices in an edge-weighted directed graph. It allows some of the edge weights
to be negative numbers, but no negative-weight cycles may exist. */

#include<iostream>
#define INF 9999
using namespace std;

int min(int a, int b);

int cost[10][10], adj[10][10];


inline int min(int a, int b){
   return (a<b)?a:b;
}

int main(){
   int vert, edge, i, j, k, c;
    
   cout << "Enter number of vertices : ";
   cin >> vert;
    
   cout << "Enter number of edges : ";
   cin >> edge;
    
   cout << "Enter the costs of edge :\n";
//   take the input and store it into adj and cost matrix
   for (k = 1; k <= edge; k++){ 
      cin >> i >> j >> c;
      adj[i][j] = cost[i][j] = c;
   }
    
   for (i = 1; i <= vert; i++)
      for (j = 1; j <= vert; j++){
         if (adj[i][j] == 0 && i != j)
         //if there is no edge, put infinity
            adj[i][j] = INF; 
      }

   for (k = 1; k <= vert; k++)
      for (i = 1; i <= vert; i++)
         for (j = 1; j <= vert; j++)
         //find minimum path from i to j through k
            adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]); 

   cout << "Resultant adjacent matrix is :\n";
   for (i = 1; i <= vert; i++){
      for (j = 1; j <= vert; j++){
         if (adj[i][j] != INF)
            cout << adj[i][j] << " ";
      }
         cout << "\n";
   }
}

/*Input :
Enter number of vertices : 3
Enter number of edges : 5
Enter the costs of edge :
1 2 8
2 1 12
1 3 22
3 1 6
2 3 4

Output :
Resultant adj matrix
0 8 12
10 0 4
6 14 0
*/