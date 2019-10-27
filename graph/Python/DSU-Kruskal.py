class Node:

    def __init__(self):
        self.nodes = []
        self.index = 0
        self.rank = 0
        self.parent = None

    def makeset(self, n):
        for i in range(0, n):
            node = Node()
            node.index = i
            node.rank = 0
            node.parent = node
            self.nodes.append(node)

    def findset(self, u):
        node = self.nodes[u]
        while node.parent != node:
            node = node.parent
        return node

    def union(self, node1, node2):
        if node1.rank > node2.rank:
            node2.parent = node1
        elif node2.rank > node1.rank:
            node1.parent = node2
        else:
            node2.parent = node1
            node1.rank += 1


def main():
    n = int(input("Enter number of nodes:"))
    node = Node()
    node.makeset(n)
    edges = int(input("Enter number of edges:"))
    lis = []
    mst = []
    for i in range(edges):
        x, y, w = input().split(' ')
        lis.append((int(w), int(x), int(y)))

    lis.sort()
    print (lis)

    for j in range(edges):
        u = lis[j][1]
        v = lis[j][2]
        a = node.findset(u)
        b = node.findset(v)
        # print (str(u) + " parent = " + str(node.nodes[u].parent.index))
        # print (str(v) + " parent = " + str(node.nodes[v].parent.index))
        if a != b:
            node.union(a, b)
            mst.append((u, v))
        # print (str(u) + " parent = " + str(node.nodes[u].parent.index))
        # print (str(v) + " parent = " + str(node.nodes[v].parent.index))
        # print ("*****")

    print (mst)

if __name__ == '__main__':
    main()