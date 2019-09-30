#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>

using namespace std;
typedef long long int lint;
bool isSafe(int start, vector <vector<int> > &A, vector<int> &P, int pos) {
	if (A[P[pos - 1]][start] == 0) {
		return false;
	}

	// check if already visited.
	for (int i = 0; i < pos; ++i) {
		if (P[i] == start) {
			return false;
		}
	}
	return true;
}

bool hamilton_cycle_upto(vector <vector<int> > &A, vector<int> &P, int N, int start) {
	// base case:
	if (start == N) {
		if ((A[P[start - 1]][P[0]]) == 1) {
			return true;
		} else {
			return false;
		}
	}
	for (int i = 1; i < N; ++i) {
		if (isSafe(i, A, P, start) == true) {

			//choose
			P[start] = i;
			//explore
			if (hamilton_cycle_upto(A, P, N, start + 1) == true) {
				return true;
			}
			// unchoose : backtrack
			P[start] = -1;
		}
	}
	return false;
}

void hamilton_cycle(vector <vector<int> > &A, int N) {
	vector <int> path(N, -1);
	path[0] = 0;
	if (hamilton_cycle_upto(A, path, N, 1) == false) {
		cout << "No Solution" << endl;
		return;
	}
	cout << "Hamilton cycle : ";
	for (int i = 0; i < N; ++i) {
		cout << path[i] << " ";
	}
	cout << path[0] << endl;
}
int main() {
	int N, M;
	cin >> N >> M;
	int u, v;
	vector <vector<int> > A(N, vector<int> (N, 0));
	for (int i = 0; i < M; ++i) {
		cin >> u >> v;
		A[u][v] = 1;
		A[v][u] = 1;
	}
	hamilton_cycle(A, N);
	return 0;
}
