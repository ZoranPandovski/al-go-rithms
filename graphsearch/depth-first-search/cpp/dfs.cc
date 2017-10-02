#include <iostream>
#include <list>

#define BIANCO 0
#define GRIGIO 1
#define NERO 2
#define INF 99999

using namespace std;

int checked[999] = {BIANCO};
int d[999] = {0};
int f[999] = {0};
int t = 1;

void dfs(list<int> lista[], int start) {
  checked[start] = GREY;
  d[start] = t++;

  for(auto it = lista[start].begin(); it != lista[start].end(); it++) {
    if(checked[*it] == WHITE)
      dfs(lista, *it);
  }

  checked[start] = BLACK;
  f[start] = t++;
        
  cout << start << '(' << d[start] << ',';
  cout << f[start] << ')' << endl;
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

	dfs(lista, 0); //0 is the start
	

	return 0;
}
