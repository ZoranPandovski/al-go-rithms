#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

//graph algorithms

//first, the quick-find function

int min(int a, int b) {
	if (a <= b) {
		return a;
	}
	return b;
}

int max(int a, int b) {
	if (a >= b) {
		return a;
	}
	return b;
}

map<int, int> quick_find(vector<vector<int> > edges) {
	//result: connected components labelled with the connected components ID
	//e.g. if (2 5 8) are in the same component and (4 9) are in the same component then (2 5 8) have ID 2 and (4 9) have ID 4
	map<int, int>ccid; //connected component ID
	for (int i = 0; i < edges.size(); ++i) {
		ccid[edges[i][0]] = edges[i][0];
		ccid[edges[i][1]] = edges[i][1];
	}
	for (int i = 0; i < edges.size(); ++i) {
		int m = min(ccid[edges[i][0]], ccid[edges[i][1]]);
		int M = max(ccid[edges[i][0]], ccid[edges[i][1]]);
		if (m == M) {
			continue;
		}
		for (auto it = ccid.begin(); it != ccid.end(); ++it) {
			int node = it->first;
			int id = it->second;
			if (id == M) {
				ccid[node] = m;
			}
		}
	}
	return ccid;
}

