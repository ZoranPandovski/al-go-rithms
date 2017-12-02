#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_N 100

int Rank[MAX_N], Root[MAX_N];

int getRoot(int node) {
    
    int parent = Root[node];
    int current = node;
    
    while(parent != current) {
        current = parent;
        parent = Root[current];
    }
        
    return parent;
}

void bind(int x, int y) {

    if(Rank[x] > Rank[y]) {
        Root[y] = x;
    } else if(Rank[x] < Rank[y]) {
        Root[x] = y;
        } else {
            Root[y] = x;
            Rank[x] ++;
        }       
}

int main() {
    
    ifstream in("in1.txt");
    
    vector<pair<int, pair<int, int> > > Edges;

    vector<pair<int, pair<int, int> > > Used;
    int cost = 0;
    
    int N, M;
    
    in >> N >> M;
    
    int i, x, y, c;
    for(i = 1; i <= M; i ++) {
        in >> x >> y >> c;
        Edges.push_back(make_pair(c, make_pair(x, y)));
    }
    
    sort(Edges.begin(), Edges.end());
    
    for(i = 1; i <= N; i ++) {
        Rank[i] = 1;
        Root[i] = i;
    }
    
    
    for(auto p : Edges) {
    
        c = p.first;
        x = p.second.first;
        y = p.second.second;
        
        // cout << x << " " << y << " " << c << "\n";
        
        if(getRoot(x) != getRoot(y)) {
        
            cout << "Add the edge " << x << " " << y << " with the cost " << c << "\n";
       
            Used.push_back(p);
            cost += c;
            
            bind(getRoot(x), getRoot(y));
        }
    }
    
    cout << "Total cost is: " << cost << "\n";
        
    return 0;
}

