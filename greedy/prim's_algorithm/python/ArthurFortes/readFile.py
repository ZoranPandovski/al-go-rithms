"""

Computer Science Department (SCC)
Mathematics and Computer Science Institute (ICMC)
University of Sao Paulo (USP)
Algorithms Projects
Teacher: Gustavo Batista
Author: Arthur Fortes da Costa

Method to Read a File

"""

from math import *


def readFile(string):
    arq = open(string, 'r')
    text = arq.readlines()

    l = []
    k = [0]
    p = [0]
    w = []
    distance = []
    no = []

    for line in text:
        k = [line[:line.find("\t")].strip(), line[line.find("\t"):].strip()]

        l.append(k)

    resp = open("dist.txt", 'w')

    for i in range(len(l)):
        no.append(str(i))
        a, b = l[i]
        distance.append((a, b))

        for j in range(i, l.__len__()):

            c, d = l[j]

            if i != j:
                d = sqrt(((float(c) - float(a)) ** 2) + ((float(d) - float(b)) ** 2))
                p = (str(i), str(j), d)
                w.append(p)

    for i in range(len(w)):
        a, b, c = w[i]
        resp.write(str(a) + "\t" + str(b) + "\t" + str(c) + "\n")

    resp.close()
    arq.close()

    return w, no, distance