#include<iostream>
#include<climits>
#include<cfloat>
using namespace std;

void printp(int* pos[] , int i,int j){
if(i==j)	cout<<i+1;
if(j>i){
	cout<<"(";
	printp(pos,i,pos[i][j]);
	printp(pos,pos[i][j]+1,j);
	cout<<")";
}
}


int main(){
int n;
cin>>n;
float p[n];
//int q[n+1];
for(int i=0;i<n;i++){cin>>p[i];}
//for(int i=0;i<n;i++){cout<<p[i]<<" ";}
//for(int i=0;i<n+1;i++){cin>>q[i];}

float e[n][n];
float w[n][n];
int root[n][n];

for(int i=0;i<n;i++){
e[i][i]=p[i];
w[i][i]=p[i];
}

for(int l=2;l<=n;l++){
	for(int i=0;i<n-l+1;i++){
		int j=i+l-1;
		e[i][j]=FLT_MAX;
		w[i][j]=w[i][j-1]+p[j];
		for(int k=i;k<=j;k++){
				if( e[i][j]>((k > i)? e[i][k-1]:0) + ((k < j)? e[k+1][j]:0) + w[i][j] ){
					e[i][j]=((k > i)? e[i][k-1]:0) + ((k < j)? e[k+1][j]:0) + w[i][j];
					root[i][j]=k;
				}
			}
		}
	}

cout<<e[0][n-1]<<endl;
int* proot[n];
for(int i=0;i<n;i++)	proot[i]=&root[i][0];
cout<<endl;
//printOBST(proot,0,n-1);	
for(int i=0;i<n;i++){
for(int j=0;j<n;j++){
cout<<root[i][j]<<" ";
}
cout<<endl;
}
return 0;
}
