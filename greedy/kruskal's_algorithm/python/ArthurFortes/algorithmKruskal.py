"""

Computer Science Department (SCC)
Mathematics and Computer Science Institute (ICMC)
University of Sao Paulo (USP)
Algorithms Projects
Teacher: Gustavo Batista
Author: Arthur Fortes da Costa

Method Kruskal

"""

from vertexFunctions import *
from readFile import readFile
from unionFind import unionFind
from operator import itemgetter


def kruskal(nodes, edges, cluster):
    forest = unionFind()
    mst = []
    for n in nodes:
        forest.add(n)

    sz = len(nodes) - 1

    for e in sorted(edges, key=itemgetter(2)):
        n1, n2, _ = e
        t1 = forest.find(n1)
        t2 = forest.find(n2)
        if t1 != t2:
            mst.append(e)
            sz -= 1
            if sz == (cluster-1):
                return mst
            forest.union(t1, t2)

edges = []
nodes = []
edges, nodes, vertex = readFile("base.txt")

result = kruskal(nodes, edges, 7)

buildVertex(vertex)

addNeighbor(result)

ColorVertex()

resp = open("kruskalCut.txt", 'w')

for u in range(len(k)):
    resp.write(str(k[u].no)+str("\n"))
    resp.write(str("Coordenada: ")+str("(")+str(k[u].dx)+str(", ")+ str(k[u].dy)+str(")")+str("\n"))
    resp.write(str("Vizinhos: ")+str(k[u].neighbor)+str("\n"))
    resp.write(str("Cor: ")+str(k[u].color)+str("\n"))
    resp.write(str("\n"))

resp.close()
dig = open("kruskal.txt", 'w')
for u in range(len(k)):
    dig.write(str(k[u].dx)+str("\t")+str(k[u].dy)+str("\t")+str(k[u].color)+str("\n"))
dig.close()
