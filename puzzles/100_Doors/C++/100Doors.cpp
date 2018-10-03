#include <iostream>

int main()
{
	bool is_open[100] = { false };

	// do the 100 passes
	for (int pass = 0; pass < 100; ++pass){
		for (int door = pass; door < 100; door += pass+1){
			is_open[door] = !is_open[door];
		}
	}

	// output the result
	for (int door = 0; door < 100; ++door){
		std::cout << "door #" << door+1 << (is_open[door]? " is open." : " is closed.") << std::endl;
	}
	return 0;
}
