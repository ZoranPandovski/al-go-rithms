a = [1, 5, 7, -1]
k = 6
N = 4
count = 0
p = {}
for i in range(N):
    if k-a[i] in p:
        # print(p[k-a[i]],i)
        count += 1
    else:
        p[a[i]] = i
print(count)
