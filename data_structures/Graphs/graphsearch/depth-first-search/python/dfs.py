
vis = []

def dfs(g, s):
    global vis

    print ('visiting ', s)
    vis[s] = True # mark s visited

    # for all adjacent vertex of s
    for u in g[s]:
        if not vis[u]:
            dfs(g, u) # visit a neighboor of s


n = int(input()) # number of vertex
m = int(input()) # number of edges

g = [[] for _ in range(n)]

for _ in range(m):
    x, y = input().split()
    g[int(x)].append(int(y))

vis = [False for _ in range(n)]

for v in range(n):
    dfs(g, v)

## Input ##
# 5
# 4
# 0 1
# 0 2
# 2 4
# 4 3
##########
## Output ##
# 5
# 4
# 0 1
# 0 2
# 2 4
# 4 3
# visiting  0
# visiting  1
# visiting  2
# visiting  4
# visiting  3
# visiting  1
# visiting  2
# visiting  3
# visiting  4
##############
