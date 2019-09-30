#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std;

int partition(int a[], int p, int r){
	int pivot=a[r];
	int ind=p;
	for(int i=p;i<=r;i++){
		if(a[i]<=pivot){
			swap(a[i],a[ind]);
			ind+=1;
		}
	}
	return (ind-1);
}

void quick_sort(int a[],int p,int r){
	int q;
	if(p<r){
		q=partition(a,p,r);
		quick_sort(a,p,q-1);  //q gives segmentation fault
		quick_sort(a,q+1,r);
	}
	return ;
}

int main(int argc, char* argv[]){
	fstream fout1("quick_sort.out",ios::out);
	ifstream file(argv[1]);
	vector<int> v;
	int num;
	int count;
	while(file>>num){
		v.push_back(num);
	}
	count=v.size();
	int a[v.size()];
	for(int i=0;i<v.size();i++){
		a[i]=v[i];
	}

	quick_sort(a,0,count-1);

	for(int i=0;i<count;i++){
		fout1<<a[i]<<endl;
	}
}
