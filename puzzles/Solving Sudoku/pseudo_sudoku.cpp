#include <bits/stdc++.h>
/*A 4x4 pseudo sudoku
with 2x2 sub grids (rest of the properties remaining identical)
*/

//Numbers represented as colors.
#define NO_COLOR 29
#define RED 2
#define YELLOW 3
#define BLUE 5
#define CYAN 7

using namespace std;

class Graph{
    int n;
    list <int> *adj;
    vector <pair<int,int>> color;
    public:
    Graph(int vertices){
        n = vertices;
        adj = new list <int> [n];
        for(int i = 0; i < 16; i++){
            color.push_back(make_pair(NO_COLOR,false));
        }
    }

    //Adjacency List representation since the graph isn't sparse.
    void addEdge(int u, int v){
        if(find(adj[u].begin(),adj[u].end(),v) == adj[u].end())
            adj[u].push_back(v);
        if(find(adj[v].begin(),adj[v].end(),u) == adj[v].end())
            adj[v].push_back(u);
    }

    void colorGraph(){
        list <int>::iterator v;
        for(int u = 0; u < 16; u++){
            int impossibleColor, possibleColor;
            //cout << "color["<< u+1 <<"].second = " << color[u].second << endl;
            if(color[u].second == false){
                if(color[u].first == NO_COLOR)
                    impossibleColor = NO_COLOR;
                else
                    impossibleColor = color[u].first;

                possibleColor = NO_COLOR;

                if(impossibleColor%RED != 0){
                    possibleColor = RED;
                    color[u].first = RED;
                    color[u].second = true;
                }
                else if(impossibleColor%YELLOW != 0){
                    possibleColor = YELLOW;
                    color[u].first = YELLOW;
                    color[u].second = true;
                }
                else if(impossibleColor%BLUE != 0){
                    possibleColor = BLUE;
                    color[u].first = BLUE;
                    color[u].second = true;
                }
                else if(impossibleColor%CYAN != 0){
                    possibleColor = CYAN;
                    color[u].first = CYAN;
                    color[u].second = true;
                }

                for(v = adj[u].begin(); v != adj[u].end(); v++){
                    if(color[*v].second == false){
                        if(color[*v].first != NO_COLOR)
                            color[*v].first = color[*v].first*possibleColor;
                        else
                            color[*v].first = possibleColor;
                    }
                }
            }
        }
        for(int u = 0; u < 16; u++){
            cout << "(" << u << "," << color[u].first << "," << color[u].second << ")" << " ";
        }
        cout << " " << endl;

        // for(int u = 0; u < 16; u++){
        //     cout << "Color of " << u+1 << " = " << color[u].first << " It is " << color[u].second << endl;
        // }
    }

    void printAdjList(){
        list <int>::iterator i;
        for(int a = 0; a < 16; a++) {
            for(i = adj[a].begin(); i != adj[a].end(); ++i) {
                cout << *i << ' ';
            }
        cout << endl;
        }
    }

};

int main(){
    //All the 16 cells of the sudoku are considered as nodes of the graph g.
    Graph g(16);

    vector <int> row1, row2, row3, row4;
    vector <int> col1, col2, col3, col4;
    vector <int> sqr1, sqr2, sqr3, sqr4;

    for(int i = 0; i < 4; i++){
        row1.push_back(i);
        row2.push_back(i+4);
        row3.push_back(i+8);
        row4.push_back(i+12);
    }

    for(int i = 0; i < 4; i++){
        col1.push_back(i*4);
        col2.push_back(i*4+1);
        col3.push_back(i*4+2);
        col4.push_back(i*4+3);
    }

    sqr1.push_back(0);
    sqr1.push_back(1);
    sqr1.push_back(4);
    sqr1.push_back(5);

    for(int i = 0; i < 4; i++){
        sqr2.push_back(sqr1[i]+2);
        sqr3.push_back(sqr1[i]+8);
        sqr4.push_back(sqr1[i]+10);
    }

    for(int u = 0; u < 16; u++){
        for(int v = u+1; v < 16; v++){
            if((find(row1.begin(),row1.end(),u) != row1.end() && find(row1.begin(),row1.end(),v) != row1.end()) || (find(row2.begin(),row2.end(),u) != row2.end() && find(row2.begin(),row2.end(),v) != row2.end()) || (find(row3.begin(),row3.end(),u) != row3.end() && find(row3.begin(),row3.end(),v) != row3.end()) || (find(row4.begin(),row4.end(),u) != row4.end() && find(row4.begin(),row4.end(),v) != row4.end()))
                g.addEdge(u,v);
            if((find(col1.begin(),col1.end(),u) != col1.end() && find(col1.begin(),col1.end(),v) != col1.end()) || (find(col2.begin(),col2.end(),u) != col2.end() && find(col2.begin(),col2.end(),v) != col2.end()) || (find(col3.begin(),col3.end(),u) != col3.end() && find(col3.begin(),col3.end(),v) != col3.end()) || (find(col4.begin(),col4.end(),u) != col4.end() && find(col4.begin(),col4.end(),v) != col4.end()))
                g.addEdge(u,v);
            if((find(sqr1.begin(),sqr1.end(),u) != sqr1.end() && find(sqr1.begin(),sqr1.end(),v) != sqr1.end()) || (find(sqr2.begin(),sqr2.end(),u) != sqr2.end() && find(sqr2.begin(),sqr2.end(),v) != sqr2.end()) || (find(sqr3.begin(),sqr3.end(),u) != sqr3.end() && find(sqr3.begin(),sqr3.end(),v) != sqr3.end()) || (find(sqr4.begin(),sqr4.end(),u) != sqr4.end() && find(sqr4.begin(),sqr4.end(),v) != sqr4.end()))
                g.addEdge(u,v);
        }
    }
    //g.printAdjList();
    g.colorGraph();

}