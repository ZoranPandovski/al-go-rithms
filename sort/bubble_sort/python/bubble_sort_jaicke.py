def bubble_sort(lista):    
    fim = len(lista) - 1 
    for i in range(fim, 0 , -1):
        for j in range(i):                
            if lista[j]>lista[j+1]:
                lista[j], lista[j+1]= lista[j+1], lista[j]                
                print(lista)
    return lista

