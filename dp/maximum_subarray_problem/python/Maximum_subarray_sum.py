from __future__ import print_function

def Max_subarray_sum(list_numbers,size):

    temp=0
    final=0

    for i in range(0,n):
        temp = max(l[i],temp+l[i])
        final = max(final,temp)

    return final


n = input()
l = []
for i in range(0,n):
    val = input()
    l = l+[val]

output = Max_subarray_sum(l,n)
print(output)
