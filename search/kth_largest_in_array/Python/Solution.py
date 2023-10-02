import random as rd

INF =float('inf')

def partition(a, l, r):
    k = l+rd.randint(0,r-l+1)
    a[l],a[k] = a[k],a[l]
    key,i = a[l],l
    for j in range(l+1,r+1):
        if a[j]<=key:
            i+=1
            a[i],a[j] = a[j],a[i]
    a[l],a[i] = a[i],a[l]
    return i

def kth_largest(a,l,r,k):
    if k>r-l+1 or k<=0:
        return INF
    p = partition(a,l,r)
    if p==r-k+1:
        return a[p]
    if p>r-k+1:
        return kth_largest(a,l,p-1,k-r+p-1)
    return kth_largest(a,p+1,r,k)

n,k = map(int,input().split())
a = list(map(int,input().split()))
ans = kth_largest(a,0,n-1,k)
if ans == INF:
    print('No Kth largest element')
else:
    print(ans)