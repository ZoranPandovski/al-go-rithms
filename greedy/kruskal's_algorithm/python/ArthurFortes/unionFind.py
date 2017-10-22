"""

Computer Science Department (SCC)
Mathematics and Computer Science Institute (ICMC)
University of Sao Paulo (USP)
Algorithms Projects
Teacher: Gustavo Batista
Author: Arthur Fortes da Costa

Method unionFind for Kruskal

"""


class unionFind(dict):
    def add(self, item):
        self[item] = item

    def find(self, item):
        parent = self[item]

        while self[parent] != parent:
            parent = self[parent]

        self[item] = parent
        return parent

    def union(self, item1, item2):
        self[item2] = self[item1]