// C++ program to print DFS traversal for a given given graph
#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    void DFSUtil(int v, bool visited[]);  // A function used by DFS
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    int DFS(bool visited[]);    // prints DFS traversal of the complete graph
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFSUtil(int v, bool visited[]){
    // Mark the current node as visited and print it
    visited[v] = true;
    // cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited);
}

// The function to do DFS traversal. It uses recursive DFSUtil()
int Graph::DFS(bool visited[]){
    int conex = 0;
    // Mark all the vertices as not visited
    // bool *visited = new bool[V];
    // for (int i = 0; i < V; i++)
    //     visited[i] = false;

    // Call the recursive helper function to print DFS traversal
    // starting from all vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false){
            DFSUtil(i, visited);
            conex++;
        }
    return conex;
}

int maior(int a, int b){
  if(a > b) return a;
  return b;
}

int main(){

  int i, j, m = 1, n, linha, coluna, result;
  char matrix[100][100];

  while(m != 0){
    cin >> m;
    if(m == 0) break;
    cin >> n;
    if(m < n){
      linha = m; coluna = n;
    }else {
      linha = n; coluna = m;
    }
    Graph maze(m * n);

    bool *visited = new bool[m * n];
    // Todos os valores já começam como visitados
    for (i = 0; i < m * n; i++)
        visited[i] = true;

    for(i = 0; i < m; i++)
      for(j = 0; j < n; j++)
        cin >> matrix[i][j];

    // Fazendo linha * i + j, temos que será possível representar uma matriz,
    // como um vetor de uma única dimensão

    for(i = 0; i < m; i++){
      for(j = 0; j < n; j++){
        if(matrix[i][j] == '@'){
          visited[linha * i + j] = false; // Um valor não é visitado Para
                                          // Poder ser analisado no DFS
          if(i - 1 >= 0){ // Uma linha acima
            if(matrix[i - 1][j] == '@')
              maze.addEdge(linha * i + j, linha * (i - 1) + j); //Mesma coluna uma linha acima
            if(j - 1 >= 0)
              if(matrix[i - 1][j - 1] == '@')
                maze.addEdge(linha * i + j, linha * (i - 1) + j - 1);
            if(j + 1 < n)
              if(matrix[i - 1][j + 1] == '@')
                maze.addEdge(linha * i + j, linha * (i - 1) + j + 1);
          }
          // Mesma linha
          if(j - 1 >= 0)
            if(matrix[i][j - 1] == '@')
              maze.addEdge(linha * i + j, linha * i + j - 1);
          if(j + 1 < n)
            if(matrix[i][j + 1] == '@')
              maze.addEdge(linha * i + j, linha * i + j + 1);
          // Uma linha abaixo
          if(i + 1 < m){
            if(matrix[i + 1][j] == '@')
              maze.addEdge(linha * i + j, linha * (i + 1) + j);
            if(j - 1 >= 0)
              if(matrix[i + 1][j - 1] == '@')
                maze.addEdge(linha * i + j, linha * (i + 1) + j - 1);
            if(j + 1 < n)
              if(matrix[i + 1][j + 1] == '@')
                maze.addEdge(linha * i + j, linha * (i + 1) + j + 1);
          }
        }
      }
    }

    result = maze.DFS(visited);
    cout << result << endl;
  }
}
