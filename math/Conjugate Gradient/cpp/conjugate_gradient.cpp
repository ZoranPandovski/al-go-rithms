#include <iostream>
#include <vector>
using namespace std;
//Naive matrix multiplications!! Anyways, to compile g++ -std=c++14 -o main conjugate_gradient.cpp
//gionuno
vector<double> conjugate_gradient(const vector<vector<double> > & A, const vector<double> & b,int T)
{
	int N = b.size();
	vector<double> r(N,0.0);
	vector<double> p(N,0.0);
	vector<double> x(N,0.0);
	for(int i=0;i<N;i++)
		p[i] = r[i] = b[i];
	int t = 0;
	while(t < T)
	{
		double rtr = 0.0;
		double ptAp = 0.0;
		for(int i=0;i<N;i++)
			rtr += r[i]*r[i];
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				ptAp += A[i][j]*p[i]*p[j];
		double alpha = rtr / (ptAp + 1e-10);
		vector<double> rn(N,0.0);
		for(int i=0;i<N;i++)
		{
			x[i] += alpha * p[i];
			rn[i] = r[i];
			for(int j=0;j<N;j++)
				rn[i] -= alpha*A[i][j]*p[j];
		}
		double rntrn = 0.0;
		for(int i=0;i<N;i++)
			rntrn += rn[i]*rn[i];
		if(rntrn < 1e-10) break;
		double beta = rntrn / rtr;
		for(int i=0;i<N;i++)
		{
			p[i] = beta*p[i] + rn[i];
			r[i] = rn[i];
		} 
		t++;
	}
	return x;
}
int main()
{
	//Only well defined for symmetric positive def matrices.
	vector<vector<double> > A(3,vector<double>(3,0.0));
	A[0][0] =  7.0; A[0][1] =  3.0; A[0][2] =  1.0;
	A[1][0] =  3.0;	A[1][1] =  7.0;
	A[2][0] =  1.0;                 A[2][2] = 10.0;
	vector<double> b(3,0.0);
	b[0] = 1.0;
	b[1] = -5.0;
	b[2] = 2.0;
	vector<double> x = conjugate_gradient(A,b,1000);
	for(int i=0;i<b.size();i++)
		cout << x[i] << endl;
	return 0;
}
