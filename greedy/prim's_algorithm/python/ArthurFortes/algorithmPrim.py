"""

Computer Science Department (SCC)
Mathematics and Computer Science Institute (ICMC)
University of Sao Paulo (USP)
Algorithms Projects
Teacher: Gustavo Batista
Author: Arthur Fortes da Costa

Method Prim

"""

from collections import defaultdict
from heapq import *
from vertexFunctions import *
from readFile import readFile


def prim(nodes, edges):
    conn = defaultdict(list)
    for n1, n2, c in edges:
        conn[n1].append((c, n1, n2))
        conn[n2].append((c, n2, n1))

    mst = []

    used = set(nodes[0])
    usable_edges = conn[nodes[0]][:]
    heapify(usable_edges)

    while usable_edges:
        cost, n1, n2 = heappop(usable_edges)
        if n2 not in used:
            used.add(n2)
            mst.append((n1, n2, cost))

            for e in conn[n2]:
                if e[2] not in used:
                    heappush(usable_edges, e)
    return mst

edges = []
nodes = []

edges, nodes, vertex = readFile("base.txt")

result = prim(nodes, edges)

buildVertex(vertex)

addNeighbor(cutPrim(result, 7))

ColorVertex()

resp = open("primCut.txt", 'w')

for u in range(len(k)):
    resp.write(str(k[u].no)+str("\n"))
    resp.write(str("Coordenada: ")+str("(")+str(k[u].dx)+str(", ")+str(k[u].dy)+str(")")+str("\n"))
    resp.write(str("Vizinhos: ")+str(k[u].neighbor)+str("\n"))
    resp.write(str("Cor: ")+str(k[u].color)+str("\n"))
    resp.write(str("\n"))

resp.close()
dig = open("prim.txt", 'w')
for u in range(len(k)):
    dig.write(str(k[u].dx)+str("\t")+str(k[u].dy)+str("\t")+str(k[u].color)+str("\n"))
dig.close()
