def cocktailSort(arr):
    n = len(arr)
    swapped = True
    start = 0
    end = n-1

    while(swapped == True):
         # reset the swapped flag on entering the loop,
        swapped = False

        for i in range(start,end):
            if(arr[i]>arr[i+1]):
                arr[i],arr[i+1] = arr[i+1],arr[i] #swap
                swapped = True

        if(swapped == False):
            break

        swapped = False

        end = end-1
        for i in range(end-1,start-1, -1):
            if(arr[i]>arr[i+1]):
                arr[i],arr[i+1] = arr[i+1],arr[i]
                swapped = True

        start = start + 1

test_arr = [4,2,3,7,5,1,0]
#output [0,1,2,3,4,5,7]
cocktailSort(test_arr)
print(test_arr)


#By Prakhar Varshney
