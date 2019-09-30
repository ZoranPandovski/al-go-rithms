#include<iostream>
#include<cmath>
using namespace std;
int **AllocateDynamicArray( int sz)
{
    int **dynamicArray;
    dynamicArray = new int*[sz];
    for( int i = 0 ; i < sz ; i++ ){
        dynamicArray[i] = new int [sz];
        for( int j = 0 ; j < sz ; j++ ){
            dynamicArray[i][j]=0;
        }
    }
    return dynamicArray;
}
void FreeDynamicArray(int** dArray)
{
    delete [] *dArray;
    delete [] dArray;
}
int **sum(int** A,int** B,int m)           //function to add two matrices of size m
{
    int **S = AllocateDynamicArray(m);
    for( int i = 0 ; i < m ; i++ ){
        for( int j = 0 ; j < m ; j++ ){
            S[i][j]=A[i][j]+B[i][j];
        }
    }
    return S;
}
int **subtract(int** A,int** B,int m)     //function to subtract two matrices of size m
{
    int **D = AllocateDynamicArray(m);
    for( int i = 0 ; i < m ; i++ ){
        for( int j = 0 ; j < m ; j++ ){
            D[i][j]=A[i][j]-B[i][j];
        }
    }
    return D;
}

int **strassen(int** A, int** B , int n){
    int **C = AllocateDynamicArray(n);
    if (n==1){
        C[0][0]=(A[0][0])*(B[0][0]);
        return C;
    }
    //dividing into sub matrices
    int **A11=AllocateDynamicArray(n/2);
    int **A12=AllocateDynamicArray(n/2);
    int **A21=AllocateDynamicArray(n/2);
    int **A22=AllocateDynamicArray(n/2);
    int **B11=AllocateDynamicArray(n/2);
    int **B12=AllocateDynamicArray(n/2);
    int **B21=AllocateDynamicArray(n/2);
    int **B22=AllocateDynamicArray(n/2);
    for(int i=0; i<n/2; i++) {
           for(int j=0; j<n/2; j++) {
              A11[i][j] = A[i][j];
              A12[i][j] = A[i][j+n/2];
              A21[i][j] = A[i+n/2][j];
              A22[i][j] = A[i+n/2][j+n/2];

              B11[i][j] = B[i][j];
              B12[i][j] = B[i][j+n/2];
              B21[i][j] = B[i+n/2][j];
              B22[i][j] = B[i+n/2][j+n/2];
        }
    }
    //recursively compute the 7 matrix products
    int **P1=strassen( sum(A11,A22,n/2) , sum(B11,B22,n/2) , n/2 );
    int **P2=strassen( sum(A21,A22,n/2) , B11 , n/2 );
    int **P3=strassen( A11 , subtract(B12,B22,n/2) , n/2 );
    int **P4=strassen( A22 , subtract(B21,B11,n/2) , n/2 );
    int **P5=strassen( sum(A11,A12,n/2) , B22 , n/2 );
    int **P6=strassen( subtract(A21,A11,n/2) , sum(B11,B12,n/2) , n/2 );
    int **P7=strassen( subtract(A12,A22,n/2) , sum(B21,B22,n/2) , n/2 );
    //calculate the resultant matrix
    int **C11=sum( (subtract( (sum(P1,P4,n/2)),P5,n/2)), P7,n/2) ;
    int **C12=sum(P3,P5,n/2);
    int **C21=sum(P2,P4,n/2);
    int **C22=sum( (subtract( sum(P1,P3,n/2),P2,n/2)), P6,n/2) ;
    //Set the result to C
    for(int i=0; i<n/2; i++) {
        for(int j=0; j<n/2; j++) {
            C[i][j] = C11[i][j];
            C[i][j+n/2] = C12[i][j];
            C[i+n/2][j] = C21[i][j];
            C[i+n/2][j+n/2] = C22[i][j];
        }
    }
    return C;
}
int main()
{
    int n,n_f;  //n_f=n_finally
    cout<<"enter size of matices: ";
    cin>>n;
    //if n!=2**k, then change n
    n_f=n;
    int c=ceil(log2(n_f));
    int f=floor(log2(n_f));
    while (c!=f){
        n_f++;
        c=ceil(log2(n_f));
        f=floor(log2(n_f));
    }
    //cout<<n<<" "<<n_f;
    int **A = AllocateDynamicArray(n_f);
    cout<<"ARRAY A: "<<endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
           cin>>A[i][j];
        }
    }
    cout<<"The first Matrix is :"<<endl;
    for(int i=0; i<n_f; i++) {
        for(int j=0; j<n_f; j++) {
           cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<"ARRAY B: "<<endl;
    int **B = AllocateDynamicArray(n_f);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
           cin>>B[i][j];
        }
    }
    cout<<"The second Matrix is :"<<endl;
    for(int i=0; i<n_f; i++) {
        for(int j=0; j<n_f; j++) {
           cout<<B[i][j]<<" ";
        }
        cout<<endl;
    }
    int **result=strassen(A,B,n_f);
    cout<<"The Resultant Matrix is :"<<endl;
    for(int i=0; i<n_f; i++) {
        for(int j=0; j<n_f; j++) {
           cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    FreeDynamicArray(A);
    FreeDynamicArray(B);
    FreeDynamicArray(result);
    return 0;
}
