"""

Computer Science Department (SCC)
Mathematics and Computer Science Institute (ICMC)
University of Sao Paulo (USP)
Algorithms Projects
Teacher: Gustavo Batista
Author: Arthur Fortes da Costa

Graph and Prim Functions

"""


class Vertex:
    def __init__(self, no, dx, dy, neighbor, color):
        self.no = no
        self.dx = dx
        self.dy = dy
        self.neighbor = neighbor
        self.color = color


k = []


def cutPrim(result, argument):
    row = 0

    while (argument-1) > 0:
        big = 0
        for i in range(len(result)):
            x, y, z = result[i]

            if z > big:
                big = z
                row = i

        result.pop(row)
        argument -= 1

    return result


def buildVertex(vertex):
    for u in range(len(vertex)):
        k.append(u)
        x, y = vertex[u]
        k[u] = Vertex(u, x, y, [], -1)


def addNeighbor(resultCut):
    for i in range(len(resultCut)):

        no1, no2, dist = resultCut[i]
        for j in range(len(k)):
            if int(no1) == k[j].no:
                k[j].neighbor.append(int(no2))
                k[int(no2)].neighbor.append(j)


def ColorVertex():
    a = 1
    for j in range(len(k)):
        if k[j].color == -1:
            bfs(j, a)
            a += 1


def bfs(j, color):
    listUse = []
    k[j].color = 8
    listUse.append(j)

    while listUse:
        var1 = listUse[0]
        listUse.pop(0)

        if k[var1].neighbor is not None:
            for f in range(len(k[var1].neighbor)):
                if k[k[var1].neighbor[f]].color == -1:
                    k[k[var1].neighbor[f]].color = 8
                    listUse.append(k[var1].neighbor[f])

        k[var1].color = color