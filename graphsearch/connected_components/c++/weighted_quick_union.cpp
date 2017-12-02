#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <map>

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

map<int, int> weighted_quick_union(vector<vector<int> > edges) {
	//result: connected components labelled with the connected components ID
	//e.g. if (2 5 8) are in the same component and (4 9) are in the same component then (2 5 8) have ID 2 and (4 9) have ID 4
	map<int, int>ccid; //connected component ID
	map<int, int>parent;//the parent node
	map<int, int>size;
	for (int i = 0; i < edges.size(); ++i) {
		parent[edges[i][0]] = edges[i][0];
		parent[edges[i][1]] = edges[i][1];
		size[edges[i][0]] = 1;
		size[edges[i][1]] = 1;
	}
	for (int i = 0; i < edges.size(); ++i) {
		int node_0 = edges[i][0];
		int node_1 = edges[i][1];
		int root_0 = node_0;
		int root_1 = node_1;
		while (root_0 != parent[root_0]) {
			root_0 = parent[root_0];
		}
		while (root_1 != parent[root_1]) {
			root_1 = parent[root_1];
		}
		if (root_0 == root_1) {
			continue;
		}
		if (size[root_0] <= size[root_1]) {
			size[root_1] = size[root_0] + size[root_1];
			parent[root_0] = root_1;
			size.erase(root_0);//we are only interested in the sizes of roots
		}
		else {
			size[root_0] = size[root_0] + size[root_1];
			parent[root_1] = root_0;
			size.erase(root_1);
		}
	}
	for (auto it = parent.begin(); it != parent.end(); ++it) {
		int node = it->first;
		int root = it->first;
		while (root != parent[root]) {
			root = parent[root];
		}
		ccid[node] = root;
	}
	return ccid;
}

int main() {
	vector<vector<int> >edges(0, vector<int>(2));
	int node1, node2;
	while (cin >> node1 >> node2) {
		vector<int>temp(2);
		temp[0] = node1;
		temp[1] = node2;
		edges.push_back(temp);
	}
	map<int, int>ccid = weighted_quick_union(edges);
	for (auto it = ccid.begin(); it != ccid.end(); ++it) {
		cout << it->first << " " << it->second << endl;
	}
}

