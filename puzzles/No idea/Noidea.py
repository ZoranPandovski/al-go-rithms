n,m=map(int,input().split())#here n is size of array and m is no. of element in sets A and B 
l=list(map(int,input().split()))#here we enter array(in python list) elements
a=set(map(int,input().split()))#here we enter set A elements
b=set(map(int,input().split()))# here we enter set B elements
happiness=0
#here we set logic that if element is in set A then happiness will be increased by one/
#and if element is in set B then happiness is decreased
for e in l:
    if e in a:
        happiness+=1
    if e in b:
        happiness-=1
print(happiness)
