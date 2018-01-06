#ifndef _TOWERS_OF_HANOI_
#define _TOWERS_OF_HANOI_

#include <iostream>

using std::cout;
using std::endl;

void print_moves(int n, int src = 1, int dest = 2, int aux = 3)
{
	if (n < 1)
		return ;

	print_moves(n - 1, src, aux, dest);

	cout << "Move: " << src << " -> " << dest << endl;

	print_moves(n - 1, aux, dest, src); 
}

#endif