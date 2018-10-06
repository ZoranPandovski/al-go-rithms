import csv
import math
import re
import sys
from itertools import cycle
from pprint import pprint
from random import *
import timeit


# Explanation :
# This is the Tabu search algorithm implemented for the Travelling Salesman problem.
# It reads the towns informations from external files (.csv, .tsp) or generates random ones and formats them, then
# starts exploring the solution space with many options (Tabu list parameters...)

#USEFULL FONCTIONS
def read_csv(csv_name):
    villes=[]
    with open(csv_name, 'rt') as f:
        reader = csv.reader(f)
        for row in reader:
            villes.append([float(row[1]), float(row[2])])
    return villes

def distance(a1, a2, b1, b2):
    w1 = a1 - b1
    w2 = a2 - b2

    w1k = w1 * w1
    w2k = w2 * w2

    suma = w1k + w2k
    return round(math.sqrt(suma), 2)

def path_length(cities, path):
    cities_pairs = zip(path, path[1:])
    consecutive_distances = [distance(cities[a][0], cities[a][1], cities[b][0], cities[b][1]) for (a, b) in
                             cities_pairs]
    return round(sum(consecutive_distances), 2)

def generate_city_coordinates(cities_count):
    axis_range = range(cities_count * 5)
    return tuple(zip(sample(axis_range, cities_count), sample(axis_range, cities_count)))

def calculate_distances(city_coordinates):
    result = []
    for city in city_coordinates:
        city_distances = []
        for other_city in city_coordinates:
            distance_ = distance(city[0], city[1], other_city[0], other_city[1])
            city_distances.append(distance_)
        result.append(city_distances)
    return result
#END USEFULL FONCTIONS



#NEIGHBOR FONCTIONS
def voisin_best_move(V,currentSol,it):
    voisin = []
    c_voisin = []
    permute = []
    cmp=0
    while(cmp<it):
        temp = currentSol[:]
        g = randint(0, len(V) - 1)
        j = randint(0, len(V) - 1)
        if( j == g ):
            j=(j+1)%len(V)
        temp[g], temp[j] = temp[j], temp[g]
        dernierElem = int(len(temp)) - 1
        temp[dernierElem] = temp[0]
        if (temp in voisin):
            pass
        else :
            x=path_length(V,temp)
            voisin.append(temp)
            c_voisin.append(x)
            cmp += 1
            if (j < g):
                permute.append([j, g])
            else:
                permute.append([g, j])

    return([voisin,c_voisin])

#NEIGHBOR FONCTIONS
def voisin_best_move2(V,currentSol,tabu,sizeMaxTabu):
    
    minc = None
    best = None
    a,b= 0,0

    for i in range(0,len(currentSol)):
        for j in range(i + 1, len(currentSol)):
            temp = currentSol[:]
            temp[i], temp[j] = temp[j], temp[i]
            if(best is None):
                if(temp in tabu):
                    continue
                else :
                    best = temp
                    minc = path_length(villes,temp)

            if ((path_length(villes, temp) < minc) and not(temp in tabu)):
                minc = path_length(villes, temp)
                best = temp[:]
                print('vosiin ',minc)
                a,b = i,j


        tabu.append(best)

        if(len(tabu)==sizeMaxTabu):
            tabu.pop(0)
    print(a, ' ', b)

    return best

    #return [voisin[c_voisin.index(min(c_voisin))],min(c_voisin),permute[c_voisin.index(min(c_voisin))]]

def voisin_first_improve(optSoFar,currentSol,V):

    bool = 0
    while True:
        temp = currentSol[:]
        g = randint(0, len(V) - 1)
        j = randint(0, len(V) - 1)
        if (j == g):
            j = (j + 1) % len(V)
        temp[g], temp[j] = temp[j], temp[g]
        dernierElem = int(len(temp)) - 1
        temp[dernierElem] = temp[0]
        x = path_length(V, temp)
        if(x<optSoFar):
            return [temp,x]

def voisin_aleatoire(currentSol,V):
    temp = currentSol[:]
    g = randint(0, len(V) - 1)
    j = randint(0, len(V) - 1)
    if (j == g):
        j = (j + 1) % len(V)
    temp[g], temp[j] = temp[j], temp[g]
    dernierElem = int(len(temp)) - 1
    temp[dernierElem] = temp[0]
    x = path_length(V, temp)
    return [temp,x]
#END VOISINAGE FONCTIONS


#GENERATION SOLUTION INITIALE
def solution_init_aleatoire(nbrVille):
    sol =[]
    for i in range(0,nbrVille): sol.append(i)
    shuffle(sol)
    sol.append(sol[0])

    return sol

#def solution_init_greedy(villes):


#END GENERATION SOLUTION INITIALE

#RECHERCHE TABOU ( avec liste tabou explicite de taille statique)
def recherche_tabou_explicite(V,nbrI,tabuTaille,voisin_parcour):

    """"" init vars (1)"""
    nbrVille = len(V)
    villes = V
    solution = []  # solution initiale


    """choix solution initiale ou greedy"""
    solution = solution_init_aleatoire(len(V))
    #solution = solution_init_greedy(villes)


    """" init vars (2)"""
    tabu = []
    tabuval = []

    tabu.append(solution)

    tabuval.append(path_length(villes, solution))
    cmp = 0
    #print("solution cout initiale ",path_length(villes, solution))
    while cmp < nbrI :

        """CHOIX FONCTION DE VOISINAGE"""
        solCourante = voisin_best_move(villes,solution,voisin_parcour)
        path_x = solCourante[0]
        x = solCourante[1]
        if (len(tabu) < tabuTaille):
            if path_x in tabu:
                pass
            else:
                tabu.append(path_x[:])
                tabuval.append(x)
                solution = path_x[:]
                cmp+=1
                #print(x)
        elif (len(tabu) == tabuTaille and x < max(tabuval)):
            if path_x in tabu:
                pass
            else:
                positionSolMax = tabuval.index(max(tabuval))
                tabu[positionSolMax] = path_x
                tabuval[positionSolMax] = x
                solution = path_x[:]
                cmp += 1
                #print(x)

    #print(tabu)
    #print(tabuval)
    indexOpt = tabuval.index(min(tabuval))
    #print("Le chemin le plus optimisé trouvé est:", tabu[indexOpt])
    #print("son cout est :", tabuval[indexOpt])
    return [tabu[indexOpt],tabuval[indexOpt]]

def recherche_tabou_attributaire(V,nbrI,tabuTaille,voisin_parcour):

    """"" init vars (1)"""

    nbrVille = len(V)
    villes = V
    solution = []  # solution initiale


    """choix solution initiale ou greedy"""
    solution = solution_init_aleatoire(len(V))

    #solution = solution_init_greedy(villes)


    """" init vars (2)"""
    tabu = []
    tabuval = []

    for i in range(1, nbrI):

        """CHOIX FONCTION DE VOISINAGE"""
        solCourante = voisin_best_move(villes,solution,voisin_parcour)
        permute = solCourante[2]
        path_x = solCourante[0]
        x = solCourante[1]
        if (len(tabu) < tabuTaille):
            if permute in tabu:
                pass
            else:
                tabu.append(permute[:])
                tabuval.append(x)
                solution = path_x[:]
                #print(x)
        elif (len(tabu) == tabuTaille and x < max(tabuval)):
            if permute in tabu:
                pass
            else:
                positionSolMax = tabuval.index(max(tabuval))
                tabu[positionSolMax] = permute
                tabuval[positionSolMax] = x
                solution = path_x[:]
                #print(x)
    #print(tabu)
    #print(tabuval)
    indexOpt = tabuval.index(min(tabuval))
    #print("Le chemin le plus optimisé trouvé est:", tabu[indexOpt])
    #print("son cout est :", tabuval[indexOpt])
    return [solCourante[0],tabuval[indexOpt]]


def recherche_tabou(V,nbrI,tabuTaille):

    """"" init vars (1)"""

    villes = V

    """choix solution initiale ou greedy"""
    Best_solution = solution_init_aleatoire(len(V))
    start = timeit.default_timer()
    init = path_length(villes,Best_solution)



    """" init vars (2)"""
    tabu = []


    tabu.append(Best_solution)

    global_ = path_length(villes, Best_solution)
    gg = Best_solution[:]


    for k in range(1, nbrI):

        """CHOIX FONCTION DE VOISINAGE"""
        minc = None
        best = None
        a, b = 0, 0

        for i in range(0, len(Best_solution)):
            for j in range(i + 1, len(Best_solution)):
                temp = Best_solution[:]
                temp[i], temp[j] = temp[j], temp[i]
                if (best is None):
                    if (temp in tabu):
                        continue
                    else:
                        best = temp
                        minc = path_length(villes, temp)

                if ((path_length(villes, temp) < minc) and not (temp in tabu)):
                    minc = path_length(villes, temp)
                    best = temp[:]
                    #print('vosiin ', minc)
                    a, b = i, j

        Best_solution = best[:]
        if(path_length(villes,Best_solution)<global_):
            global_ = path_length(villes,Best_solution)
            gg = Best_solution[:]


        tabu.append(Best_solution)
        if(len(tabu) == tabuTaille):
            tabu.pop(0)

        toto = path_length(villes,Best_solution)

        cycleDet =' '
        cycleDet= cycleDet +' '+ str(toto)
        print(toto)

    regex = re.compile(r'(.+ .+)( \1)+')
    match = regex.search(cycleDet)
    try:
        print(match.group(0))
    except:
        print("no cycle")

    stop = timeit.default_timer()
    return best,init,global_,stop-start


def recherche_tabou2(V,nbrI,tabuTaille):

    """"" init vars (1)"""

    villes = V
    #print("inside_1")
    """choix solution initiale ou greedy"""
    Best_solution = solution_init_aleatoire(len(V))
    #print("inside_2")
    start = timeit.default_timer()
    init = path_length(villes,Best_solution)



    """" init vars (2)"""
    tabu = []


    tabu.append(Best_solution)

    global_ = path_length(villes, Best_solution)
    #print("inside_3")
    gg = Best_solution[:]


    for k in range(1, nbrI):

        """CHOIX FONCTION DE VOISINAGE"""
        minc = None
        best = None
        a, b = 0, 0
        done = False;

        for i in range(0, len(Best_solution)):
            for j in range(i + 1, len(Best_solution)):
                temp = Best_solution[:]
                temp[i], temp[j] = temp[j], temp[i]
                if (best is None):
                    if (temp in tabu):
                        continue
                    else:
                        best = temp
                        minc = path_length(villes, temp)

                if ((path_length(villes, temp) < minc) and not (temp in tabu)):
                    minc = path_length(villes, temp)
                    best = temp[:]
                    #print('vosiin ', minc)
                    a, b = i, j
                    if(path_length(villes, temp) < global_):
                        done = True
                        break
            if(done):
                break

        #print("inside_4")
        Best_solution = best[:]
        if(path_length(villes,Best_solution)<global_):
            global_ = path_length(villes,Best_solution)
            gg = Best_solution[:]


        tabu.append(Best_solution)
        if(len(tabu) == tabuTaille):
            tabu.pop(0)

        toto = path_length(villes,Best_solution)

        cycleDet =' '
        cycleDet= cycleDet +' '+ str(toto)
        print(toto)

    regex = re.compile(r'(.+ .+)( \1)+')
    match = regex.search(cycleDet)
    try:
        print(match.group(0))
    except:
        print("no cycle")

    stop = timeit.default_timer()
    return best,init,global_,stop-start

def recherche_tabou_att(V,nbrI,tabuTaille):

    """"" init vars (1)"""

    villes = V

    """choix solution initiale ou greedy"""
    Best_solution = solution_init_aleatoire(len(V))
    start = timeit.default_timer()
    init = path_length(villes,Best_solution)



    """" init vars (2)"""
    tabu = []

    global_ = path_length(villes, Best_solution)
    gg = Best_solution[:]


    for k in range(0, nbrI):

        """CHOIX FONCTION DE VOISINAGE"""
        minc = None
        best = None
        a, b = 0, 0

        for i in range(0, len(Best_solution)):
            for j in range(i + 1, len(Best_solution)):
                temp = Best_solution[:]
                temp[i], temp[j] = temp[j], temp[i]
                per=[i,j]
                if (best is None):
                    if (per in tabu):
                        continue
                    else:
                        best = temp
                        a,b=i,j
                        minc = path_length(villes, temp)

                if ((path_length(villes, temp) < minc) and not (per in tabu)):
                    minc = path_length(villes, temp)
                    best = temp[:]
                    a, b = i, j


        Best_solution = best[:]
        if(path_length(villes,Best_solution)<global_):
            global_ = path_length(villes,Best_solution)
            gg = Best_solution[:]

        #print('a:b  ', a, ' ', b)
        #print(tabu)
        tabu.append([a,b])
        if(len(tabu) == tabuTaille):
            tabu.pop(0)

        toto = path_length(villes,Best_solution)

        cycleDet =' '
        cycleDet= cycleDet +' '+ str(toto)
        print(toto)

    regex = re.compile(r'(.+ .+)( \1)+')
    match = regex.search(cycleDet)
    try:
        print(match.group(0))
    except:
        print("no cycle")


    stop = timeit.default_timer()
    return best,init,global_,stop-start


def recherche_tabou_att2(V,nbrI,tabuTaille):

    """"" init vars (1)"""

    villes = V

    """choix solution initiale ou greedy"""
    Best_solution = solution_init_aleatoire(len(V))
    start = timeit.default_timer()
    init = path_length(villes,Best_solution)



    """" init vars (2)"""
    tabu = []

    global_ = path_length(villes, Best_solution)
    gg = Best_solution[:]
    done = False


    for k in range(0, nbrI):

        """CHOIX FONCTION DE VOISINAGE"""
        minc = None
        best = None
        a, b = 0, 0

        for i in range(0, len(Best_solution)):
            for j in range(i + 1, len(Best_solution)):
                temp = Best_solution[:]
                temp[i], temp[j] = temp[j], temp[i]
                per=[i,j]
                if (best is None):
                    if (per in tabu):
                        continue
                    else:
                        best = temp
                        a,b=i,j
                        minc = path_length(villes, temp)

                if ((path_length(villes, temp) < minc) and not (per in tabu)):
                    minc = path_length(villes, temp)
                    best = temp[:]
                    a, b = i, j
                    if(path_length(villes, temp) <global_):
                        done=True
                        break
            if(done):
                break



        Best_solution = best[:]
        if(path_length(villes,Best_solution)<global_):
            global_ = path_length(villes,Best_solution)
            gg = Best_solution[:]

        #print('a:b  ', a, ' ', b)
        #print(tabu)
        tabu.append([a,b])
        if(len(tabu) == tabuTaille):
            tabu.pop(0)

        toto = path_length(villes,Best_solution)

        cycleDet =' '
        cycleDet= cycleDet +' '+ str(toto)
        print(toto)

    regex = re.compile(r'(.+ .+)( \1)+')
    match = regex.search(cycleDet)
    try:
        print(match.group(0))
    except:
        print("no cycle")


    stop = timeit.default_timer()
    return best,init,global_,stop-start

def recherche_tabou_asp(V,nbrI,tabuTaille):

    """"" init vars (1)"""

    villes = V

    """choix solution initiale ou greedy"""
    Best_solution = solution_init_aleatoire(len(V))
    start = timeit.default_timer()
    init = path_length(villes,Best_solution)



    """" init vars (2)"""
    tabu = []


    tabu.append(Best_solution)

    global_ = path_length(villes, Best_solution)
    gg = Best_solution[:]


    for k in range(1, nbrI):

        """CHOIX FONCTION DE VOISINAGE"""
        minc = None
        best = None
        a, b = 0, 0

        for i in range(0, len(Best_solution)):
            for j in range(i + 1, len(Best_solution)):
                temp = Best_solution[:]
                temp[i], temp[j] = temp[j], temp[i]
                if (best is None):
                    if (temp in tabu):
                        if(path_length(villes,temp)<global_):
                            best = temp
                            minc = path_length(villes, temp)
                        else:
                            continue
                    else:
                        best = temp
                        minc = path_length(villes, temp)

                if ((path_length(villes, temp) < minc) ):
                    if(not (temp in tabu) or (path_length(villes, temp) < global_)):
                        minc = path_length(villes, temp)
                        best = temp[:]
                        #print('vosiin ', minc)
                        a, b = i, j


        Best_solution = best[:]
        if(path_length(villes,Best_solution)<global_):
            global_ = path_length(villes,Best_solution)
            gg = Best_solution[:]


        tabu.append(Best_solution)
        if(len(tabu) == tabuTaille):
            tabu.pop(0)

        toto = path_length(villes,Best_solution)

        cycleDet =' '
        cycleDet= cycleDet +' '+ str(toto)
        print(toto)

    regex = re.compile(r'(.+ .+)( \1)+')
    match = regex.search(cycleDet)
    try:
        print(match.group(0))
    except:
        print("no cycle")


    stop = timeit.default_timer()
    return best,init,global_,stop-start

def recherche_tabou_asp2(V,nbrI,tabuTaille):

    """"" init vars (1)"""

    villes = V

    """choix solution initiale ou greedy"""
    Best_solution = solution_init_aleatoire(len(V))
    start = timeit.default_timer()
    init = path_length(villes,Best_solution)



    """" init vars (2)"""
    tabu = []


    tabu.append(Best_solution)

    global_ = path_length(villes, Best_solution)
    gg = Best_solution[:]
    done = False


    for k in range(1, nbrI):

        """CHOIX FONCTION DE VOISINAGE"""
        minc = None
        best = None
        a, b = 0, 0

        for i in range(0, len(Best_solution)):
            for j in range(i + 1, len(Best_solution)):
                temp = Best_solution[:]
                temp[i], temp[j] = temp[j], temp[i]
                if (best is None):
                    if (temp in tabu):
                        if(path_length(villes,temp)<global_):
                            best = temp
                            minc = path_length(villes, temp)
                        else:
                            continue
                    else:
                        best = temp
                        minc = path_length(villes, temp)

                if ((path_length(villes, temp) < minc) ):
                    if(not (temp in tabu) or (path_length(villes, temp) < global_)):
                        minc = path_length(villes, temp)
                        best = temp[:]
                        #print('vosiin ', minc)
                        a, b = i, j
                if(path_length(villes, temp) < global_):
                    done = True
                    break
            if(done):
                break


        Best_solution = best[:]
        if(path_length(villes,Best_solution)<global_):
            global_ = path_length(villes,Best_solution)
            gg = Best_solution[:]


        tabu.append(Best_solution)
        if(len(tabu) == tabuTaille):
            tabu.pop(0)

        toto = path_length(villes,Best_solution)

        cycleDet =' '
        cycleDet= cycleDet +' '+ str(toto)
        print(toto)

    regex = re.compile(r'(.+ .+)( \1)+')
    match = regex.search(cycleDet)
    try:
        print(match.group(0))
    except:
        print("no cycle")


    stop = timeit.default_timer()
    return best,init,global_,stop-start


def recherche_tabou_att_asp(V,nbrI,tabuTaille):

    """"" init vars (1)"""
    

    villes = V

    """choix solution initiale ou greedy"""
    Best_solution = solution_init_aleatoire(len(V))

    start = timeit.default_timer()
    init = path_length(villes,Best_solution)


    """" init vars (2)"""
    tabu = []

    global_ = path_length(villes, Best_solution)
    gg = Best_solution[:]


    for k in range(0, nbrI):

        """CHOIX FONCTION DE VOISINAGE"""
        minc = None
        best = None
        a, b = 0, 0

        for i in range(0, len(Best_solution)):
            for j in range(i + 1, len(Best_solution)):
                temp = Best_solution[:]
                temp[i], temp[j] = temp[j], temp[i]
                per=[i,j]
                if (best is None):
                    if (per in tabu):
                        if((path_length(villes, temp) < global_)):
                            best = temp
                            a, b = i, j
                            minc = path_length(villes, temp)
                        else:
                            continue
                    else:
                        best = temp
                        a,b=i,j
                        minc = path_length(villes, temp)

                if ((path_length(villes, temp) < minc) ):
                    if(not (per in tabu) or (path_length(villes, temp) < global_)):
                        minc = path_length(villes, temp)
                        best = temp[:]
                        a, b = i, j


        Best_solution = best[:]
        if(path_length(villes,Best_solution)<global_):
            global_ = path_length(villes,Best_solution)
            gg = Best_solution[:]

        #print('a:b  ', a, ' ', b)
        #print(tabu)
        tabu.append([a,b])
        if(len(tabu) == tabuTaille):
            tabu.pop(0)

        toto = path_length(villes,Best_solution)

        cycleDet =' '
        cycleDet= cycleDet +' '+ str(toto)
        print(toto)

    regex = re.compile(r'(.+ .+)( \1)+')
    match = regex.search(cycleDet)
    try:
        print(match.group(0))
    except:
        print("no cycle")


    stop = timeit.default_timer()
    return best,init,global_,stop-start

def recherche_tabou_att_asp2(V,nbrI,tabuTaille):

    """"" init vars (1)"""
    

    villes = V

    """choix solution initiale ou greedy"""
    Best_solution = solution_init_aleatoire(len(V))

    start = timeit.default_timer()
    init = path_length(villes,Best_solution)


    """" init vars (2)"""
    tabu = []

    global_ = path_length(villes, Best_solution)
    gg = Best_solution[:]
    done = False


    for k in range(0, nbrI):

        """CHOIX FONCTION DE VOISINAGE"""
        minc = None
        best = None
        a, b = 0, 0

        for i in range(0, len(Best_solution)):
            for j in range(i + 1, len(Best_solution)):
                temp = Best_solution[:]
                temp[i], temp[j] = temp[j], temp[i]
                per=[i,j]
                if (best is None):
                    if (per in tabu):
                        if((path_length(villes, temp) < global_)):
                            best = temp
                            a, b = i, j
                            minc = path_length(villes, temp)
                        else:
                            continue
                    else:
                        best = temp
                        a,b=i,j
                        minc = path_length(villes, temp)

                if ((path_length(villes, temp) < minc) ):
                    if(not (per in tabu) or (path_length(villes, temp) < global_)):
                        minc = path_length(villes, temp)
                        best = temp[:]
                        a, b = i, j
                if(path_length(villes, temp) < global_):
                    done = True
                    break
            
            if(done):
                break


        Best_solution = best[:]
        if(path_length(villes,Best_solution)<global_):
            global_ = path_length(villes,Best_solution)
            gg = Best_solution[:]

        #print('a:b  ', a, ' ', b)
        #print(tabu)
        tabu.append([a,b])
        if(len(tabu) == tabuTaille):
            tabu.pop(0)

        toto = path_length(villes,Best_solution)

        cycleDet =' '
        cycleDet= cycleDet +' '+ str(toto)
        print(toto)

    regex = re.compile(r'(.+ .+)( \1)+')
    match = regex.search(cycleDet)
    try:
        print(match.group(0))
    except:
        print("no cycle")


    stop = timeit.default_timer()
    return best,init,global_,stop-start


def tabu(nbrI,sizeTabu,tbench,asp,typeTabu,tv):

    print("start loading benchmark ...")
    if(tbench=="1"): V = read_csv("cities.csv")
    elif (tbench=="2"): V = read_csv("a280.csv")
    elif (tbench=="3"): V = read_csv("d493.csv")
    else : V = read_csv("pr2392.csv")
    print("end loading benchmark ...")

    if(tv=="mv"):
        if(asp=="sans"):
            if(typeTabu=="explicite"):
                return recherche_tabou(V,nbrI,sizeTabu)
            else:
                return recherche_tabou_att(V, nbrI, sizeTabu)
        else:
            if (typeTabu == "explicite"):
                return recherche_tabou_asp(V, nbrI, sizeTabu)
            else:
                return recherche_tabou_att_asp(V, nbrI, sizeTabu)
    else:
        if(asp=="sans"):
            if(typeTabu=="explicite"):
                return recherche_tabou2(V,nbrI,sizeTabu)
            else:
                return recherche_tabou_att2(V, nbrI, sizeTabu)
        else:
            if (typeTabu == "explicite"):
                return recherche_tabou_asp2(V, nbrI, sizeTabu)
            else:
                return recherche_tabou_att_asp2(V, nbrI, sizeTabu)



if __name__ == '__main__':
    #villes = read_csv("cities.csv")
    villes =[[1150.0,1760.0],[630.0,1660.0],[40.0  ,2090.0],[750.0  ,1100.0],[750.0  ,2030.0],[1030.0 , 2070.0],[1650.0  , 650.0],[1490.0  ,1630.0],[790.0  ,2260.0],[710.0  ,1310.0],[840.0  , 550.0],[1170.0 , 2300.0],[970.0  ,1340.0],[510.0  , 700.0],[750.0  , 900.0],[1280.0 , 1200.0],[230.0  , 590.0],[460.0  , 860.0],[1040.0 ,  950.0],[590.0  ,1390.0],[830.0  ,1770.0],[490.0  , 500.0],[1840.0 , 1240.0],[1260.0 , 1500.0],[1280.0 ,  790.0],[490.0  ,2130.0],[1460.0 , 1420.0],[1260.0 , 1910.0],[360.0  ,1980.0]]
    res = recherche_tabou(villes,100,17,20)
    print("Best optimal path : ", res[0])
    print("Its cost : ", res[1])
    #villes = generate_city_coordinates(5)
    #bm = voisin_best_move(villes,[0,1,2,3,4,0],5)
    #fi = voisin_first_improve(path_length(villes,bm[0]),[0,1,2,3,4,0],villes)
    #print(bm)
    #print(fi)
    #print(solution_init_aleatoire(10))

