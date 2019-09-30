"""
this algorithm was made based on the existing pseudocode 
in the 3rd version of the Cormen's book.
"""

n=[int(x) for x in input().split()]
for j in range(len(n)):
    chave=n[j]
    i=j-1
    while (i>=0) and (n[i]>chave):
        n[i+1],n[j-1]=n[i],n[j]
        i-=1
        j-=1
print(n)
