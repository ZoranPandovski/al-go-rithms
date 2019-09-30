n=int(input())
a=[]
for i in range(0,n):
    c=0
    for j in range(0,3):
        c=c+int(input())
    a=a+[c]
for i in range(0,len(a)):
    j=i-1
    h=i
    while j>=0 and a[j]<a[h]:
        c=a[h]
        del a[h]
        a.insert(j,c)
        j-=1
        h-=1
print(a)
