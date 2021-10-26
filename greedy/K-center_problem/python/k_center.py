import networkx as nx
import matplotlib.pyplot as plt
import operator



def k_centers(G, n):
    centers = []
    cities = G.nodes()
    #add an arbitrary node, here, the first node,to the centers list
    centers.append((G.nodes())[0])
    cities.remove(centers[0])
    n = n-1 #since we have already added one center
    #choose n-1 centers
    while n!= 0:
        city_dict = {}
        for cty in cities:
            min_dist = float("inf")
            for c in centers:
                min_dist = min(min_dist,G[cty][c]['length'])
            city_dict[cty] = min_dist
        #print city_dict
        new_center = max(city_dict, key = lambda i: city_dict[i])
        #print new_center
        centers.append(new_center)
        cities.remove(new_center)
        n = n-1
    #print centers
    return centers



#takes input from the file and creates a weighted undirected graph
def CreateGraph():
    G = nx.Graph()
    f = open('input.txt')
    n = int(f.readline()) #n denotes the number of cities
    wtMatrix = []
    for i in range(n):
        list1 = map(int, (f.readline()).split())
        wtMatrix.append(list1)
    #Adds egdes along with their weights to the graph
    for i in range(n) :
        for j in range(n)[i:] :
            G.add_edge(i, j, length = wtMatrix[i][j])
    noc = int(f.readline()) #noc,here,denotes the number of centers
    return G, noc



#draws the graph and displays the weights on the edges
def DrawGraph(G, centers):
    pos = nx.spring_layout(G)
    color_map = ['blue'] * len(G.nodes())
    #all the center nodes are marked with 'red'
    for c in centers:
        color_map[c] = 'red'
    nx.draw(G, pos, node_color = color_map, with_labels = True)  #with_labels=true is to show the node number in the output graph
    edge_labels = nx.get_edge_attributes(G, 'length')
    nx.draw_networkx_edge_labels(G, pos, edge_labels = edge_labels, font_size = 11) #prints weight on all the edges



#main function
if __name__ == "__main__":
    G,n = CreateGraph()
    centers = k_centers(G, n)
    DrawGraph(G, centers)
    plt.show()
