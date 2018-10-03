#include <bits/stdc++.h>

//Sudoku's numbers represented as colors.
#define NO_COLOR 29
#define RED 2
#define YELLOW 3
#define BLUE 5
#define CYAN 7
#define PINK 11
#define GRAY 13
#define GREEN 17
#define WHITE 19
#define BLACK 23

using namespace std;

class Graph{
    int n;
    list <int> *adj;
    vector <int> subgrid, subgridIter;
    vector <pair<int,int>> color;
    public:
    Graph(int vertices){
        n = vertices;
        adj = new list <int> [n];
        for(int i = 0; i < 81; i++){
            color.push_back(make_pair(NO_COLOR,false));
        }
        subgrid.push_back(0);
        subgrid.push_back(1);
        subgrid.push_back(2);
        subgrid.push_back(11);
        subgrid.push_back(20);
        subgrid.push_back(19);
        subgrid.push_back(18);
        subgrid.push_back(9);
        subgrid.push_back(10);

        subgridIter.push_back(0);
        subgridIter.push_back(3);
        subgridIter.push_back(6);
        subgridIter.push_back(27);
        subgridIter.push_back(30);
        subgridIter.push_back(33);
        subgridIter.push_back(54);
        subgridIter.push_back(57);
        subgridIter.push_back(60);

    }

    //Adjacency List representation since the graph isn't sparse.
    //It has 30% of the edges compared to a full graph.
    void addEdge(int u, int v){
        if(find(adj[u].begin(),adj[u].end(),v) == adj[u].end())
            adj[u].push_back(v);
        if(find(adj[v].begin(),adj[v].end(),u) == adj[v].end())
            adj[v].push_back(u);
    }

    void colorGraph(){
        list <int>::iterator v;
        vector <int>::iterator i, j;
        for(i = subgridIter.begin(); i < subgridIter.end(); i++){   
            for(j = subgrid.begin(); j < subgrid.end(); j++){
                int u = *i + *j;
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
                    else if(impossibleColor%PINK != 0){
                        possibleColor = PINK;
                        color[u].first = PINK;
                        color[u].second = true;
                    }
                    else if(impossibleColor%GRAY != 0){
                        possibleColor = GRAY;
                        color[u].first = GRAY;
                        color[u].second = true;
                    }
                    else if(impossibleColor%GREEN != 0){
                        possibleColor = GREEN;
                        color[u].first = GREEN;
                        color[u].second = true;
                    }
                    else if(impossibleColor%WHITE != 0){
                        possibleColor = WHITE;
                        color[u].first = WHITE;
                        color[u].second = true;
                    }
                    else if(impossibleColor%BLACK != 0){
                        possibleColor = BLACK;
                        color[u].first = BLACK;
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
                // for(int u = 0; u < 81; u++){
                //     cout << "(" << u << "," << color[u].first << "," << color[u].second << ")" << " ";
                // }
                // cout << " " << endl;
            }
            for(int u = 0; u < 81; u++){
                cout << "Color of " << u+1 << " = " << color[u].first << " It is " << color[u].second << endl;
            }
        }
    }

    void printAdjList(){
        list <int>::iterator i;
        for(int a = 0; a < 81; a++) {
            for(i = adj[a].begin(); i != adj[a].end(); ++i) {
                cout << *i << ' ';
            }
        cout << endl;
        }
    }

};

int main(){
    //All the 81 cells of a sudoku are considered as nodes of the graph g.
    Graph g(81);

    vector <int> row1, row2, row3, row4, row5, row6, row7, row8, row9;
    vector <int> col1, col2, col3, col4, col5, col6, col7, col8, col9;
    vector <int> sqr1, sqr2, sqr3, sqr4, sqr5, sqr6, sqr7, sqr8, sqr9;

    for(int i = 0; i < 9; i++){
        row1.push_back(i);
        row2.push_back(i+9);
        row3.push_back(i+18);
        row4.push_back(i+27);
        row5.push_back(i+36);
        row6.push_back(i+45);
        row7.push_back(i+54);
        row8.push_back(i+63);
        row9.push_back(i+72);
    }

    for(int i = 0; i < 9; i++){
        col1.push_back(i*9);
        col2.push_back(i*9+1);
        col3.push_back(i*9+2);
        col4.push_back(i*9+3);
        col5.push_back(i*9+4);
        col6.push_back(i*9+5);
        col7.push_back(i*9+6);
        col8.push_back(i*9+7);
        col9.push_back(i*9+8);
    }

    sqr1.push_back(0);
    sqr1.push_back(1);
    sqr1.push_back(2);
    sqr1.push_back(9);
    sqr1.push_back(10);
    sqr1.push_back(11);
    sqr1.push_back(18);
    sqr1.push_back(19);
    sqr1.push_back(20);

    for(int i = 0; i < 9; i++){
        sqr2.push_back(sqr1[i]+3);
        sqr3.push_back(sqr1[i]+6);
        sqr4.push_back(sqr1[i]+27);
        sqr5.push_back(sqr1[i]+30);
        sqr6.push_back(sqr1[i]+33);
        sqr7.push_back(sqr1[i]+54);
        sqr8.push_back(sqr1[i]+57);
        sqr9.push_back(sqr1[i]+60);
    }

    /*Creating the graph for sudoku.
    Every node (or cell) has an edge with another node (or cell),
    if they have a row in common or a column in common or belong to the same square.
    Squares of the sudoku are the 9 squares inside which a number from 1-9 cannot be
    repeated.
    */

    for(int u = 0; u < 81; u++){
        for(int v = u+1; v < 81; v++){
            if((find(row1.begin(),row1.end(),u) != row1.end() && find(row1.begin(),row1.end(),v) != row1.end()) || (find(row2.begin(),row2.end(),u) != row2.end() && find(row2.begin(),row2.end(),v) != row2.end()) || (find(row3.begin(),row3.end(),u) != row3.end() && find(row3.begin(),row3.end(),v) != row3.end()) || (find(row4.begin(),row4.end(),u) != row4.end() && find(row4.begin(),row4.end(),v) != row4.end()) || (find(row5.begin(),row5.end(),u) != row5.end() && find(row5.begin(),row5.end(),v) != row5.end()) || (find(row6.begin(),row6.end(),u) != row6.end() && find(row6.begin(),row6.end(),v) != row6.end()) || (find(row7.begin(),row7.end(),u) != row7.end() && find(row7.begin(),row7.end(),v) != row7.end()) || (find(row8.begin(),row8.end(),u) != row8.end() && find(row8.begin(),row8.end(),v) != row8.end()) || (find(row9.begin(),row9.end(),u) != row9.end() && find(row9.begin(),row9.end(),v) != row9.end()))
                g.addEdge(u,v);
            if((find(col1.begin(),col1.end(),u) != col1.end() && find(col1.begin(),col1.end(),v) != col1.end()) || (find(col2.begin(),col2.end(),u) != col2.end() && find(col2.begin(),col2.end(),v) != col2.end()) || (find(col3.begin(),col3.end(),u) != col3.end() && find(col3.begin(),col3.end(),v) != col3.end()) || (find(col4.begin(),col4.end(),u) != col4.end() && find(col4.begin(),col4.end(),v) != col4.end()) || (find(col5.begin(),col5.end(),u) != col5.end() && find(col5.begin(),col5.end(),v) != col5.end()) || (find(col6.begin(),col6.end(),u) != col6.end() && find(col6.begin(),col6.end(),v) != col6.end()) || (find(col7.begin(),col7.end(),u) != col7.end() && find(col7.begin(),col7.end(),v) != col7.end()) || (find(col8.begin(),col8.end(),u) != col8.end() && find(col8.begin(),col8.end(),v) != col8.end()) || (find(col9.begin(),col9.end(),u) != col9.end() && find(col9.begin(),col9.end(),v) != col9.end()))
                g.addEdge(u,v);
            if((find(sqr1.begin(),sqr1.end(),u) != sqr1.end() && find(sqr1.begin(),sqr1.end(),v) != sqr1.end()) || (find(sqr2.begin(),sqr2.end(),u) != sqr2.end() && find(sqr2.begin(),sqr2.end(),v) != sqr2.end()) || (find(sqr3.begin(),sqr3.end(),u) != sqr3.end() && find(sqr3.begin(),sqr3.end(),v) != sqr3.end()) || (find(sqr4.begin(),sqr4.end(),u) != sqr4.end() && find(sqr4.begin(),sqr4.end(),v) != sqr4.end()) || (find(sqr5.begin(),sqr5.end(),u) != sqr5.end() && find(sqr5.begin(),sqr5.end(),v) != sqr5.end()) || (find(sqr6.begin(),sqr6.end(),u) != sqr6.end() && find(sqr6.begin(),sqr6.end(),v) != sqr6.end()) || (find(sqr7.begin(),sqr7.end(),u) != sqr7.end() && find(sqr7.begin(),sqr7.end(),v) != sqr7.end()) || (find(sqr8.begin(),sqr8.end(),u) != sqr8.end() && find(sqr8.begin(),sqr8.end(),v) != sqr8.end()) || (find(sqr9.begin(),sqr9.end(),u) != sqr9.end() && find(sqr9.begin(),sqr9.end(),v) != sqr9.end()))
                g.addEdge(u,v);
        }
    }
    //g.printAdjList();
    g.colorGraph();

}