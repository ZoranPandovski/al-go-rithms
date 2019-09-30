/**
 * Given an undirected graph and a number m, determine if the graph can be
 * colored with at most m colors such that no two adjacent vertices of the
 * graph are colored with same color
 */
#include <bits/stdc++.h>
using namespace std;

bool isSafe(int v, auto& graph, auto& color, int node, int c) {
	// Check if adjacent vertices of node are of same color
	for (int i = 0; i < v; i++)
		if (graph[node][i] == 1 && color[i] == c)
			return false;

	return true;
}

bool colorGraph(int v, auto& graph, auto& color, int m, int node) {
	if (node >= v) {
		// Print colors assigned to vertices
		for (int i = 0; i < color.size(); i++)
			cout << color[i] << ' ';
		cout << endl;
		return true;
	}

	for (int c = 1; c <= m; c++) {
		if (isSafe(v, graph, color, node, c)) {
			color[node] = c;

			// Recur to assign colors to other vertices
			if (colorGraph(v, graph, color, m, node+1))
				return true;

			// If vertex can't be colored, backtrack
			color[node] = 0;
		}
	}
	return false;
}

int main() {
	int v, m;
	cin >> v >> m;

	vector<vector<int>> graph(v, vector<int>(v));
	for (int i = 0; i < v; i++)
		for (int j = 0; j < v; j++)
			cin >> graph[i][j];

	// All vertices colored zero initially
	vector<int> color(v, 0);

	if (!colorGraph(v, graph, color, m, 0))
		cout << "No solution exists...\n";

	return 0;
}
