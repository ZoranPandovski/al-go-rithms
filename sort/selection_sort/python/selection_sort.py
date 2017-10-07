#defines functions to swap two list elements
def swap(A,i,j):
    temp = A[i]
    A[i] = A[j]
    A[j] = temp

#defines functions to print list
def printList(A,n):
    for  i in range(0,n):
        print(A[i],"\t")


def selectionSort(A,n):
    for start in range(0,n-1):
        min=start #min is the index of the smallest element in the list during the iteration
        #Scan from A[min+1] to A[n-1] to find a list element that is smaller than A[min]
        for cur in range(min+1,n):
            #if A[cur] is smaller than A[min] min is updated
            if A[cur]<A[min]:
                min = cur
        #the two elements are swapped
        swap(A,start,min)
            
def test():
    A = [38,58,13, 15,21,27,10,19,12,86,49,67,84,60,25]
    n = len(A)
    print("Selection Sort: ")
    selectionSort(A,n)
    print("Sorted List: ")
    printList(A,n)

test()
