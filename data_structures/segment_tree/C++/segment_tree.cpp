#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
// segment tree is like binary tree but stores indexes instead of values.
// with this way it is possible to check out an index of minimum value in an interval
// this is a powerful structre that can be used in algorithm challanges
// for example: largest rectangle question in hackerrank.

// TODO, goksgie: convert this implementation to a class
using namespace std;
vector<long> inputArray;
vector<long> segmentTree;

pair<long, long> getMin(pair<long,long> f1, pair<long,long> f2){
	if(f1.second == -1) return f2;
	if(f2.second == -1) return f1;
	return (f1.second < f2.second)? f1:f2;
}

pair<long,long> generateSegmentTreeUtil(long left, long right, long treeIndex){
	if(left == right){
		segmentTree[treeIndex] = left;
		return make_pair(segmentTree[treeIndex],inputArray[left]);
	}
	long mid = left + (right - left) /2;
	pair<int,int> temp = getMin(generateSegmentTreeUtil(left,mid,2*treeIndex+1),
								generateSegmentTreeUtil(mid+1,right,2*treeIndex+2));
	segmentTree[treeIndex] = temp.first;
	return temp;
}

void generateSegmentTree(){
	long size = ceil(log2(inputArray.size()));
	long max_size = 2*pow(2,size) -1;
	segmentTree = vector<long>(max_size,-1);
	generateSegmentTreeUtil(0,inputArray.size()-1,0);
}

void printTree(){
	for(int i =0; i<segmentTree.size(); i++){
		cout<<segmentTree[i]<<endl;
	}
}

pair<long,long> getMinIntervalUtil(long start, long end, long left, long right, long treeIndex){
	//cout<<start<<" "<<end<<endl;
	if(start>=left && end <=right){
		long index = segmentTree[treeIndex];
		return make_pair(index,inputArray[index]);
	}
	if(end < left || start > right) return make_pair(-1,-1);
	long mid = start + (end - start)/2;
	return getMin(getMinIntervalUtil(start, mid, left,right,2*treeIndex+1),getMinIntervalUtil(mid+1,end,left,right,2*treeIndex+2));
}

long getMinInterval(long left, long right){
	if(left > right || right > inputArray.size() -1 ){
		return -1;
	}
	return getMinIntervalUtil(0,inputArray.size()-1,left,right,0).first;
}

int main(void){
	inputArray = vector<long>{0,10,2,3,4,5,1};
	generateSegmentTree();
	printTree();
	cout<<"*******"<<endl;
	cout<<getMinInterval(0,6)<<endl;
	cout<<"*******"<<endl;
	cout<<getMinInterval(2,4)<<endl;
}