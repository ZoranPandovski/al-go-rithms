#Fibonacci search for sorted algorithm
def fibSearch(arr,x):

    #fibonacci numbers initialization
    fib2 = 0
    fib1 = 1
    fib = fib2 + fib1

    n = len(arr)
    #find the smallest fibonacci greater than or equal to array length
    while (fib < n):
        fib2 = fib1
        fib1 = fib
        fib = fib2 + fib1

    #the leftout list for the array
    offset = -1

    while (fib > 1):
        #check if fib2 is a valid index
        i = min(offset+fib2, n-1)

        #if x is greater than the value at index fib2,
        #cut the array from offset to i
        if (arr[i] < x):
            fib = fib1
            fib1 = fib2
            fib2 = fib - fib1
            offset = i

        #if x is smaller than the value at index fib2,
        #cut the array after i+1
        elif (arr[i] > x):
            fib = fib2
            fib1 = fib1 - fib2
            fib2 = fib - fib1

        #return i when element is found
        else :
            return i

    #compare last element with x
    if (fib1 and arr[offset+1] == x):
        return offset+1

    #when element not found return -1
    return -1

arr = [10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100]
x = 85
print ("Found at index: ", fibSearch(arr, x))
