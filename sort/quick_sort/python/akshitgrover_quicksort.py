n=int(input())
def quicksort(b,s,e):
    if(s<e):
        pindex=partition(b,s,e)
        for i in range(0,n):
            print(b[i],end=" ")
        print()
        quicksort(b,s,pindex-1)
        quicksort(b,pindex+1,e)
def partition(c,s,e):
    pindex=s
    for i in range(s,e):
        if(c[i]<=c[e]):
            c[i],c[pindex]=c[pindex],c[i]
            pindex+=1
    c[pindex],c[e]=c[e],c[pindex]
    return pindex
a=input()
a=a.split()
for i in range(0,n):
    a[i]=int(a[i])
quicksort(a,0,n-1)
        
    
