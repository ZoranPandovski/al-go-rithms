#include <iostream.h>

#include "pernicious.hpp"

using namespace std;

int main()
{
	for (int i = 0; i <= 19; i++)
		if (is_pernicious(i))
			cout << i << " is pernicious" << endl;
		else
			cout << i << " is not pernicious" << endl;

	return 0; 
}