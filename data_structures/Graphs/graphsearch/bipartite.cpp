#include <iostream>
#include <queue>

#define RED 0
#define BLUE 1

/* 
    WHITE  -> not discovered
    GREY  -> discovered
    BLACK -> done
*/
#define WHITE 0
#define GREY 1
#define BLACK 2

using namespace std;

class Node
{
  private:
    int val;
    Node *next;

    friend class Graph;

  public:
    Node(int val)
    {
        this->val = val;
        this->next = 0;
    }
};

class Graph
{
  private:
    int no_v;
    Node **adj;

    int scan_list_for_undiscovered(int[], int) const;

  public:
    // Parametrized Constructor
    Graph(int);

    // Setter Method
    void AddEdge(int, int);

    // Application Methods
    bool Bipartite() const;
    void ShowGraph() const;
};

Graph::Graph(int no_v)
{
    this->no_v = no_v;

    adj = new Node *[no_v];

    for (int i = 0; i < no_v; i++)
    {
        adj[i] = 0;
    }
}

void Graph::AddEdge(int u, int v)
{
    Node *new_node = new Node(v);

    if (!adj[u])
    {
        adj[u] = new_node;
    }
    else
    {
        new_node->next = adj[u];
        adj[u] = new_node;
    }
}

bool Graph::Bipartite() const
{
    queue<int> q;

    int arr_disc[no_v] = {WHITE};

    int color[no_v] = {-1};

    q.push(0);
    arr_disc[0] = GREY;
    color[0] = RED;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        arr_disc[v] = BLACK;

        Node *ptr = adj[v];

        while (ptr)
        {
            if (arr_disc[ptr->val] == WHITE)
            {
                q.push(ptr->val);
                arr_disc[ptr->val] = GREY;

                if (color[v] == RED)
                    color[ptr->val] = BLUE;
                else
                    color[ptr->val] = RED;
            }

            else
            {
                if (color[ptr->val] == color[v])
                    return false;
            }
            ptr = ptr->next;
        }
    }

    return true;
}

void Graph::ShowGraph() const
{
    for (int i = 0; i < no_v; i++)
    {
        cout << i << " ->  ";

        Node *ptr = adj[i];

        while (ptr)
        {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }

        cout << "\n";
    }

    return;
}

int main()
{
    cout << "\nenter no of vertices : ";
    int no_v;
    cin >> no_v;

    Graph graph(no_v);

    cout << "enter 0 for directed and 1 for undirected graph : ";
    int choice;
    cin >> choice;

    cout << "\nenter (u,v) pair in the graph (-1 to exit): ";
    int u, v;

    while (1)
    {
        cin >> u;

        if (u == -1)
            break;

        cin >> v;

        graph.AddEdge(u, v);

        if (choice == 1)
            graph.AddEdge(v, u);
    }

    graph.ShowGraph();

    if (graph.Bipartite())
        cout << "\nis bipartite";
    else
        cout << "\nnot bipartite";

    return 0;
}
