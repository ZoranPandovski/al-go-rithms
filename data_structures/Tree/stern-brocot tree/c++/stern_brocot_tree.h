#include <list>
#include <iostream>
using namespace std;
class stern_brocot
{
public:
	int index = 0, user_index = 0;
	list<pair<int, int>> list1;
	list<pair<int, int>> list2;
	list<list<pair<int, int>>> list3;

	stern_brocot() //constructor
	{
		list1.push_back(make_pair(0, 1));
		list1.push_back(make_pair(1, 0));
	}

	void make_tree(int num, int den); //function to make tree
	void print(void); //function to print stern_brocot tree
	void findLR(void); //function to print the path of fraction
};
