#include <iostream>

#include "towers_of_hanoi.hpp"

using std::cout;
using std::endl;

int main()
{
	cout << "Towers of Hanoi with 3 disks" << endl;
	print_moves(3);

	cout << "Towers of Hanoi with 4 disks" << endl;
	print_moves(4, 1, 2, 3);

	return 0;
}