def sort(ar,f):
        for j in range (1,f):
            k = j-1
            key = ar[j]
            while k >= 0 and key < ar[k]:
                ar[k+1] = ar[k]
                k -= 1
            ar[k+1] = key
        return ar

def bucketsort(n1,n2,b,n,bucket):
    for i in range (len(n)):
        j = int((n[i]-n1)/R)
        bucket[j].append(n[i])
    for i in range (b):
        f = len(bucket[i])
        bucket[i] = sort(bucket[i],f)
    ar = []
    for i in range (b):
        ar.extend(bucket[i]) 
    return ar

n1,n2,b = input().strip().split(' ')
n1,n2,b = [int(n1) , int(n2) , int(b)]
n = list(map(int, input().strip().split(' ')))
R = (n2-n1)/b
bucket = [[] for i in range (b)]
result = bucketsort(n1,n2,b,n,bucket)
print (result)


