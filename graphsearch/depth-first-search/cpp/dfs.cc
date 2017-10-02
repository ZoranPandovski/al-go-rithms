#include <iostream>
#include <list>

#define WHITE 0
#define GREY 1
#define BLACK 2
#define INF 99999

using namespace std;

int checked[INF] = {WHITE};
int d[INF] = {0};
int f[INF] = {0};
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
	
	/* example:
	http://pages.cs.wisc.edu/~mcw/cs367/lectures/images/dfs.gif
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
	2(3,4)
	4(6,7)
	3(5,8)
	1(2,9)
	5(10,11)
	0(1,12)
	*/
	return 0;
}
