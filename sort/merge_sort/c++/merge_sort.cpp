#include<iostream>
#include<cstdlib>
#include<fstream>
#include<vector>

using namespace std;

void merge(int v[],int p,int q,int r){
	int a[r-p+1];
	int i=p,j=q+1,k=0;
	while(i<=q && j<=r){
		if(v[i]<v[j]){
			a[k]=v[i];
			i=i+1;
			k=k+1;
		}
		else{
			a[k]=v[j];
			j=j+1;
			k=k+1;
		}
	}
	if(i>q){
		while(j<=r){
			a[k]=v[j];
			k=k+1;
			j=j+1;
		}
	}
	else{
		while(i<=q){
			a[k]=v[i];
			i=i+1;
			k=k+1;
		}
	}
	for(int i=p;i<=r;i++){
		v[i]=a[i-p];
	}

}

void merge_sort(int v[],int p,int r){
	if(p<r){
		int q=(p+r)/2;
		merge_sort(v,p,q);
		merge_sort(v,q+1,r);
		merge(v,p,q,r);
	}
	return;
}

int main(int argc, char* argv[]){
	fstream fout("merge_sort.out",ios::out);
	ifstream file(argv[1]);
	vector<int> v;
	int num;
	int count;
	while(file>>num){
		v.push_back(num);
	}
	count=v.size();
	int b[v.size()];	
	for(int i=0;i<v.size();i++){
		b[i]=v[i];
	}
    
	merge_sort(b,0,count-1);

	for(int i=0;i<count;i++){
		fout<<b[i]<<endl;
	}
}
