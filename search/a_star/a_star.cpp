/*
code for example in README file
we can get heuristics and g(n), 
(which is cost of cost of the path from the start node to nth node)
and f(n), which is sum of heuristics and g(n).
*/


#include <iostream>
using namespace std;

#define NUM 7
#define line1 4
#define line2 3

int main() {
	float citydist[NUM] = { 0.0 };
	int heuristicdist[NUM] = { 0 };
	//array to save information temporarily
	char city[NUM] = { 'X', 'A', 'B', 'C', 'D', 'E', 'Y' };
	//X is start node and Y is goal node
	char next1[line1] = { 'A', 'B', 'C', 'Y' };
	char next2[line2] = { 'D', 'E', 'Y' };
	float citydist1[line1] = { 2, 3, 1.5, 4 };
	float citydist2[line2] = { 3.5, 1, 2 };
	//initialize

	int h[NUM] = { 0 };
	float g[NUM] = { 0 }, f[NUM] = { 0 };
	//array for h(n)(heuristics), g(n), and f(n)
	
	//get heuristics
	//count from next1 or next2 until we reach 'Y' 
	for(int i = 0; i < line1; i++){
		for (int j = i; j < line1; j++) {
			if(next1[j] != 'Y')
				heuristicdist[i]++;
		}
	}
	for (int i = 4; i < NUM; i++) {
		for (int j = i-4; j < line2; j++) {
			if (next2[j] != 'Y')
				heuristicdist[i]++;
		}
	}
	//heuristic distances are stored in the order of the city array
	
	
	//get g(n)
	//approach each next1, next2 and increase corresponding citydistance
	for (int i = 0; i < line1; i++) {
		for (int j = 0; j < i+1; j++) {
			citydist[i] += citydist1[j];
		}
	}
	for (int i = line1; i < NUM; i++) {
		for (int j = 0; j < i-line1+1; j++) {
			citydist[i] += citydist2[j];
		}
	}

	for (int i = 0; i < NUM; i++) {
		if (i < line1 - 1) {
			h[i + 1] = heuristicdist[i];
			g[i + 1] = citydist[i];
		}
		if (i > line1 - 1) { 
			h[i] = heuristicdist[i]; 
			g[i] = citydist[i];
		}
	}
	//set proper value of h(n) and g(n) using temporary array

	//get f(n)
	for (int i = 0; i < NUM; i++) {
		f[i] = h[i] + g[i];
	}

	//print result - f(n), g(n), h(n) of each cities
	cout << "city" << endl;
	for (int i = 0; i < NUM; i++)
		cout << city[i] << "	";
	cout << endl<<"citydist" << endl;
	for (int i = 0; i < NUM; i++)
		cout << g[i] << "	";
	cout << endl << "heuristic" << endl;
	for (int i = 0; i < NUM; i++)
		cout << h[i] << "	";
	cout << endl << "total" << endl;
	for (int i = 0; i < NUM; i++)
		cout << f[i] << "	";

}
