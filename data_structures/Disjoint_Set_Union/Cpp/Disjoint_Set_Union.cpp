#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5+5;

int p[maxn], size[maxn];

void initialize(int n){
	for(int i = 1; i<=n; i++){
		p[i] = i;
		size[i] = 1;
	}
	return ;
}

int find(int u){
	return p[u] = (p[u] == u ? u : find(p[u])); //path compression
}

//weighted union for maintaing balance
void join(int u, int v){
	int uu = find(u), vv = find(v);

	//they are already connected
	if(uu == vv)
		return ;

	if(size[uu] < size[vv]){
		p[uu] = vv;

		size[vv] += size[uu];
	} else{
		p[vv] = uu;

		size[uu] += size[vv];
	}

	return ;
}

int main(){
	int n = 5;

	initialize(n);

	join(1, 2);
	join(2, 3);
	join(4, 5);

	//finding in which connected component 2 lies
	cout << find(2) << endl;

	return 0;
}