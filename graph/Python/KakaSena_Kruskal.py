grafo = {
    'a': {'b': 0, 'd': 1, 'e': 2},
    'b': {'a': 0, 'c': 4, 'e': 5},
    'c': {'b': 4, 'e': 7},
    'd': {'a': 1, 'e': 9},
    'e': {'a': 2, 'b': 5, 'c': 7, 'd': 9, 'f': 14},
    'f': {'e': 14}
}

def quicksort(vetor,inicio,fim):
    if(inicio < fim):
        q = pQSort(vetor,inicio,fim) #q[0] = pivo; q[1] = inicio; q[2] = fim
        quicksort(vetor, q[1],q[0]-1) #(vetor, inicio, pivo-1)
        quicksort(vetor, q[0]+1,q[2]) #(vetor, pivo+1, fim)

def pQSort(vetor,inicio,fim):
    pivo = vetor[fim]
    i = inicio-1

    for j in range(inicio,fim):
        if(peso(grafo, vetor[j]) <= peso(grafo, pivo)):
            i += 1
            vetor[i],vetor[j] = vetor[j],vetor[i]

    vetor[i+1],vetor[fim] = vetor[fim],vetor[i+1]
    return i+1,inicio,fim

def peso(grafo, aresta):
    return grafo[aresta[0]][aresta[1]]

def ordena_arestas(grafo):
    arestas_ordenadas = []
    for u,vizinhos in grafo.iteritems():
        for v,peso in vizinhos.iteritems():
            arestas_ordenadas.append(tuple([u, v]))
    quicksort(arestas_ordenadas,0,len(arestas_ordenadas)-1)
    return arestas_ordenadas

sets = {}

def makeSet(x):
    sets[x] = set([x])

def find(x):
    for representative,subset in sets.iteritems():
        if x in subset:
            return representative
    return None

def union(x, y):
    xRepresentative = find(x)
    yRepresentative = find(y)
    sets[yRepresentative] = sets[yRepresentative].union(sets[xRepresentative])
    del sets[xRepresentative]

def kruskal(grafo):
    arestas_ordenadas = ordena_arestas(grafo)
    arvore_geradora_minima = []
    for v in grafo.keys():
        makeSet(v)
    for aresta in arestas_ordenadas:
        if find(aresta[0]) != find(aresta[1]):
            arvore_geradora_minima.append(aresta)
            union(aresta[0], aresta[1])

    return arvore_geradora_minima




arvore_geradora_minima = kruskal(grafo)