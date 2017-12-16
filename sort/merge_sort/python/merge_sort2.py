print("Enter the list of numbers to be sorted:")
s=input()
if(s[-1]==" "):
	s=s[0:len(s)-1:1]
s=list(map(int,s.split(" ")))

#MERGE SORT
def merge(a,b,c):
	k=0
	i=0
	j=0
	while(len(a)>i and len(b)>j):
		if(a[i]>=b[j]):
			c[k]=b[j]
			j+=1
		else:
			c[k]=a[i]
			i+=1
		k+=1
	while(len(a)>i):
		c[k]=a[i]
		k+=1
		i+=1
	while(len(b)>j):
		c[k]=b[j]
		k+=1
		j+=1
def mergesort(l):
	if(len(l)<2):
		return
	mid=len(l)//2
	L=l[0:mid:1]
	R=l[mid:len(l):1]
	mergesort(L)
	mergesort(R)
	merge(L,R,l)
mergesort(s)
print(" ".join(list(map(str,s))))