def sort(l):
    n = l[-1]
    prime = [True for i in range(n + 1)]
    p = 2
    while (p * p <= n):
        if (prime[p] == True):
             
            for i in range(p ** 2, n + 1, p):
                prime[i] = False
        p += 1
    prime[0]= False
    prime[1]= False
    
    for i in range(len(l)):
        if prime[l[i]] or l[i]%5==0:
            l[i] = 0
    return l

def Fibonacci(n):
    l = []
    f1 = 0
    f2 = 1
    if (n < 1):
        return
    for x in range(1, n):
        l.append(f2)
        next = f1 + f2
        f1 = f2
        f2 = next
    return l
 
 

n
l = Fibonacci(n+1)
l = sort(l)
print(l)
