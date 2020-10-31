import time
n = 100000000000000000000000000000000000000000

#It took only --- 0.002832174301147461 seconds --- to complete the code. 
def printfib(previous, latest, n):
    if(latest > n):
        return
    print(', ', latest, end='')
    printfib(latest, previous + latest, n)


start_time = time.time()
print(0, end='')
printfib(0, 1, n)
print(" ")
print("--- %s seconds ---" % (time.time() - start_time))
