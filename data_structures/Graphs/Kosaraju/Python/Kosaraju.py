lst = []
def dfs(start, g, visit):
    global lst
    visit[start] = True
    if start in g:
        for i in g[start]:
            if not visit[i]:
                dfs(i, g, visit)
                lst.append(i)

def countSCCs(g, v):
    global lst
    lst = []
    visit = [False] * n
    for i in range(n):
        if not visit[i]:
            dfs(i, g, visit)
            lst.append(i)
    rev = dict()
    for i in g:
        for j in g[i]:
            if j not in rev:
                rev[j] = [i, ]
            else:
                rev[j].append(i)
    visit = [False] * n
    ans = 0
    while len(lst):
        curr = lst.pop()
        if not visit[curr]:
            ans += 1
            visit[curr] = True
            dfs(curr, rev, visit)
    return ans


import sys
from collections import defaultdict

sys.setrecursionlimit(10 ** 6)


def creategraph(e, arr, graph):
    i = 0
    while i < 2 * e:
        graph[arr[i]].append(arr[i + 1])
        i += 2



t = int(input())
for i in range(t):
    n, e = list(map(int, input().strip().split()))
    arr = list(map(int, input().strip().split()))
    graph = defaultdict(list)
    creategraph(e, arr, graph)
    print(countSCCs(graph, n))
