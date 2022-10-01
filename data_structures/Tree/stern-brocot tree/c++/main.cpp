#include "stern_brocot.h"
int main(void)
{
	stern_brocot tree;
	int user_num, user_den;
	cout << "Please insert the fraction you want to know the paths." << endl << "1. numerator : ";
	cin >> user_num; //user_num is the numerator that user enters
	cout << "2. denominator : ";
	cin >> user_den; //user_den is the denominator tha user enters

	if (user_num - int(user_num) != 0 || user_den - int(user_den) != 0 || user_num <= 0 || user_den <= 0) //if user_num or user_den is not int type, or if user_num or user_den is not positive
	{
		cout << "Input error" << endl;
		return 0;
	}

	else
	{
		for (int i = 2; i <= user_num && i <= user_den;) //making the fraction to irreducible fraction
		{
			if (user_num % i == 0 && user_den % i == 0)
				user_num /= i, user_den /= i;
			else
				i++;
		}
		tree.make_tree(user_num, user_den); //make stern-brocot tree
	}
	tree.print(); //print the tree
	tree.findLR(); //print the path of fraction
}
