// g[v] contains edge ids leading out of node v

template <typename T>
class Graph {
  struct Edge {
    int from;
    int to;
    T cost;
  };
  
  int n;
  vector<vector<int>> g;
  vector<Edge> edges;
  
  Graph(int _n) : n(_n) {
    g.resize(n);
  }
  
  void add(int from, int to, T cost = 1) {
    assert(0 <= from && from < n && 0 <= to && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
  }
};
