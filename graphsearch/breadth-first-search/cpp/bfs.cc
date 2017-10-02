#include <iostream>
#include <list>
#include <queue>

#define WHITE 0
#define GREY 1
#define BLACK 2
#define INF 99999

using namespace std;

int checked[INF] = {WHITE};
int d[INF] = {0};
int f[INF] = {0};
int t = 1;

void bfs(const list<int> lista[], int start) {
    queue<int> coda;

    int checked[999] = {WHITE};
    
    coda.push(start);
    
    checked[start] = GREY;
    while(!coda.empty()) {
        int corrente = coda.front();
        coda.pop();

        if(checked[corrente] == GREY) {
            cout << corrente << ' ';
            for(auto it = lista[corrente].begin(); it != lista[corrente].end(); ++it) {
                coda.push(*it);
                if(checked[*it] != BLACK)
                    checked[*it] = GREY;
            }
            checked[corrente] = BLACK;
        }
    }
}

int main() {
	int u, w;
	int e;
	cin >> e;
	list<int> lista[INF];
	for(int i = 0; i < e; ++i) {
		cin >> u >> w;
		lista[u].push_back(w);
	}

	bfs(lista, 0); //0 is the start
	
	/* example:
	http://pages.cs.wisc.edu/~mcw/cs367/lectures/images/bfs.gif
	#input
	8
	0 1
	0 5
	1 2
	2 0
	1 3
	3 4
	4 2
	1 4
	#output
	0 1 5 2 3 4
	*/
	return 0;
}
