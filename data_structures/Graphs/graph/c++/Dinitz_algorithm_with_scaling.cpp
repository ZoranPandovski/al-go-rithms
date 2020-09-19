#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
const int N = 501*501, M = 10001*10;
long long n, m, x, y, cap, cost, sz;
long long d[N], s, f, i;
vector<long long> v[N];
long long q[N], stq, enq;
long long push, pos[N], ans;

struct edge {
	long long y, cap, flow;
}e[M];

long long limit = 1<<30;

inline void add_edge() {
	edge e1 = {y, cap, 0}, e2 = {x, 0, 0};
	v[x].push_back(sz);
	e[sz++] = e1;
	v[y].push_back(sz);
	e[sz++] = e2;
}

inline bool bfs() {
	q[++enq] = s;
	d[s] = 1;
	while (stq < enq) {
		x = q[++stq];
		for (i = 0; i < (int)v[x].size(); ++i) {
			int id = v[x][i], to = e[id].y;
			 if (d[to] == 0 && e[id].flow + limit <= e[id].cap)
			 	d[to] = d[x]+1, q[++enq] = to;
		}
	}
	return d[f] != 0;
}

inline long long dfs(long long x, long long flow) {
	if (x == f) return flow;
	if (!flow) return 0;
	for (; pos[x] < (int)v[x].size(); ++pos[x]) {
		int id = v[x][pos[x]], to = e[id].y;
		if(d[to] == d[x] + 1) { 	
			long long pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
			if(pushed) {
				e[id].flow += pushed;
				e[id^1].flow -= pushed;
				return pushed;
			}
		}
	}
	return 0;
}

inline void dinitz() {
	memset(pos, 0, sizeof(pos));
	memset(d, 0, sizeof(d));
	enq = stq = 0;
	while (bfs()) {
		while (true) {
			long long push = dfs(s, 1 << 30);
			if(!push) break;
			ans += push;
		}
		memset(pos, 0, sizeof(pos));
		memset(d, 0, sizeof(d));
		enq = stq = 0;
	}
}

int main() {
	freopen("flow2.in", "r", stdin);
	freopen("flow2.out", "w", stdout);
	scanf("%lld %lld", &n, &m);
	for(i = 1; i <= m; ++i) {
		scanf("%lld %lld %lld", &x, &y, &cap);
		add_edge();
	}
	s = 1, f = n;
	for(limit = 1 << 30; limit > 0; limit >>= 1) {
		dinitz();
	}
	printf("%lld", ans);
return 0;}