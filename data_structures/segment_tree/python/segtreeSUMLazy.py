from math import *
 
def constructtree(begin,end,pos):
	if begin == end:
		stree[pos] = val[begin]
		return
	mid = begin + (end-begin)//2
	constructtree(begin,mid,pos*2+1)
	constructtree(mid+1,end,pos*2+2)
	stree[pos] = stree[2*pos+1] + stree[2*pos+2]
	return
 
def updateTreeUtil(index,delta,begin,end,pos):
	if index<begin or index>end:
		return
	if begin == end:
		stree[pos] += delta
		return
	mid = begin + (end-begin)//2
	updateTreeUtil(index,delta,begin,mid,2*pos+1)
	updateTreeUtil(index,delta,mid+1,end,2*pos+2)
	stree[pos] = stree[2*pos+1] + stree[2*pos+2]
 
def updateTree(index,delta):
	val[index]+=delta
	updateTreeUtil(index,delta,0,n-1,0)
 
def updateTreeRangeUtil(startRange,endRange,delta,begin,end,pos):
	if begin>end or startRange>end or endRange<begin:
		return
	if begin==end:
		stree[pos] += delta
		return
	mid = begin + (end-begin)//2
	updateTreeRangeUtil(startRange,endRange,delta,begin,mid,2*pos+1)
	updateTreeRangeUtil(startRange,endRange,delta,mid+1,end,2*pos+2)
	stree[pos] = stree[2*pos+1] + stree[2*pos+2]
 
def updateTreeRange(startRange,endRange,delta):
	i = startRange
	while i<=endRange:
		val[i] += delta
		i += 1
	updateTreeRangeUtil(startRange,endRange,delta,0,n-1,0)
 
def query(pos,begin,end,left,right):
	if left>end or right<begin:
		return 0
	if left<=begin and right>=end:
		return stree[pos]
	mid = begin + (end-begin)//2
	return query(2*pos+1,begin,mid,left,right)+query(2*pos+2,mid+1,end,left,right)
 
def updateTreeLazy(startRange,endRange,delta,begin,end,pos):
	if begin>end:
		return
 
	if not lazy[pos]==0:
		stree[pos] += (end-begin+1)*lazy[pos]
		if not begin==end:
			lazy[2*pos+1] += lazy[pos]
			lazy[2*pos+2] += lazy[pos]
		lazy[pos] = 0
 
	if startRange>end or endRange<begin:
		return
 
	if startRange<=begin and endRange>=end:
		stree[pos] += (end-begin+1)*delta
		if not begin==end:
			lazy[2*pos+1] += delta
			lazy[2*pos+2] += delta
		return
 
	mid = begin + (end-begin)//2
	updateTreeLazy(startRange,endRange,delta,begin,mid,2*pos+1)
	updateTreeLazy(startRange,endRange,delta,mid+1,end,2*pos+2)
	stree[pos] = stree[2*pos+1] +stree[2*pos+2]
 
def queryLazy(pos,begin,end,left,right):
	if begin>end:
		return 0
 
	if not lazy[pos]==0:
		stree[pos] += (end-begin+1)*lazy[pos]
		if not begin==end:
			lazy[2*pos+1] += lazy[pos]
			lazy[2*pos+2] += lazy[pos]
		lazy[pos] = 0
 
	if left>end or right<begin:
		return 0
 
	if left<=begin and right>=end:
		return stree[pos]
 
	mid = begin + (end-begin)//2
	return queryLazy(2*pos+1,begin,mid,left,right)+queryLazy(2*pos+2,mid+1,end,left,right)
 

# Taking required initial inputs
n,c = map(int,input("Enter the number of elements and number of queries : ").split())
val = list(map(int,input(f"Enter {n} elements seperated by space : ").split()))

# Initializing and constructing the initial segment tree
slen = 2*(2**int(ceil(log(n,2))))
stree = [0] * slen
lazy = [0] * slen
print(n,c)
constructtree(0,n-1,0)

print("Enter",c,"queries with 1 based indexing")
print("TYPES OF QUERY -:")
print("FOR UPDATE => 0 STARTRANGE ENDRANGE DELTA")
print("FOR RANGE SUM QUERY => 1 STARTRANGE ENDRANGE")

while c:
	query = list(map(int,input("Enter query : ").split()))
	if query[0] == 0:
		updateTreeLazy(query[1]-1,query[2]-1,query[3],0,n-1,0)
	elif query[0] == 1:
		print("The range sum is :",queryLazy(0,0,n-1,query[1]-1,query[2]-1))
	c -= 1