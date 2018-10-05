#include <functional>
#include <iostream>
#include <chrono>
#include <random>
#include <cmath>
using namespace std;
//VEGAS Estimation of the integral of 1d function with T estimates.
//To compile: g++ -std=c++14 -o main vegas_algorithm.cpp
//gionuno
double vegas_algorithm(const std::function<double(double)> & f,double a,double b,int K = 256,int T=100,int S=100000)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine gen(seed);
    std::uniform_real_distribution<double> dist(0.0,1.0);
	
	vector<double> g(K,0.0);
	for(int t=0;t<T;t++)
	{
		for(int k=0;k<K;k++)
		{
			double y = (b-a)*(dist(gen)+k)/K+a;
			g[k] += fabs(f(y))/T;
		}
	}
	
	double s_g = 0.0;
	for(int k=0;k<K;k++) s_g += g[k];
	for(int k=0;k<K;k++) g[k] /= s_g;
	
	std::discrete_distribution<int> bin_dist(g.begin(),g.end());
	double I = 0.0;
	for(int s=0;s<S;s++)
	{
		int z = bin_dist(gen);
		double x = (b-a)*(dist(gen)+z)/K+a;
		I += (b-a)*f(x)/(g[z]*K*S);
	}
	return I; 
}
int main()
{
	cout.precision(17);
	cout << "pi approx " << fixed << 2.0*vegas_algorithm([](double x)->double{ return sqrt(1.0-x*x);},-1.0,1.0) << endl;
	return 0;
}
