//
//  main.cpp
//  backToProblemSolving
//
//  Created by Khaled Abdelfattah on 6/27/17.
//  Copyright © 2017 Khaled Abdelfattah. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define MAX 1000000000
#define BASE1 23
#define BASE2 31
#define MOD1 1000000007
#define MOD2 217645177
#define EPS 1e-6
#define SIZE 20005

int n, m;
vector<pair<pair<int, int>, int>> edges;
int bestDist[SIZE];

void Bellman_Ford (int s) {
    memset(bestDist, INT_MAX, n + 1);
    bestDist[s] = 0;
    for (int i = 0; i < n - 1; i ++) {
        bool relaxed = false;
        for (int j = 0; j < edges.size(); j ++) {
            int from = edges[j].first.first, to = edges[j].first.second;
            int dist = edges[j].second;
            if (bestDist[from] + dist < bestDist[to]) {
                bestDist[to] = bestDist[from] + dist;
                relaxed = true;
            }
        }
        if (!relaxed)
            break;
    }
}

bool hasNegCycle () {
    for (int j = 0; j < edges.size(); j ++) {
        int from = edges[j].first.first, to = edges[j].first.second;
        int dist = edges[j].second;
        if (bestDist[from] + dist < bestDist[to]) {
            return true;
        }
    }
    return false;
}
int main() {
    n = 6;
    m = 5;
    edges.push_back(make_pair(make_pair(1, 2), -2));
    edges.push_back(make_pair(make_pair(1, 3), 5));
    edges.push_back(make_pair(make_pair(2, 3), -2));
    edges.push_back(make_pair(make_pair(3, 4), 7));
    edges.push_back(make_pair(make_pair(4, 5), -12));
    Bellman_Ford(1);
    for (int i = 1; i <= n; i ++) 
        cout << bestDist[i] << " ";
    cout << endl;
    cout << hasNegCycle();
    return 0;
}
