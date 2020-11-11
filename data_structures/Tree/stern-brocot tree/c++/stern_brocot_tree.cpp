#include "stern_brocot.h"
void stern_brocot::make_tree(int num, int den) //function to make stern_brocot tree
{
	int numerator1, numerator2, denominator1, denominator2, numerator, denominator;
	int number = 1, user_index2 = 0;
	bool stop = false;
	list2.operator=(list1);
	auto iter = begin(list2); //iter means the begin of list2

	for (int i = 0; i < index; i++)
		number *= 2;

	for (int i = 0; i < number; i++)
	{
		numerator1 = list1.front().first, denominator1 = list1.front().second; //numerator1=m, denominator1=n
		list1.pop_front();
		numerator2 = list1.front().first, denominator2 = list1.front().second; //numerator2=m', denominator2=n'
		numerator = numerator1 + numerator2, denominator = denominator1 + denominator2; //numerator=m+m', denominator=n+n'
		user_index2++;
		advance(iter, 1); //increase iter by 1
		list2.insert(iter, 1, make_pair(numerator, denominator)); //insert the pair to the list2

		if (numerator == num && denominator == den) //if we found numerator and denominator that user entered
		{
			user_index = user_index2; //user_index is used in the function findLR
			stop = true;
		}
	}

	index++;
	list1.operator=(list2);
	list3.push_back(list2); //push one level of the tree to list3

	if (stop == false) //if we couldn't find the numerator and denominator that user entered
		make_tree(num, den);
	else //if we found the numerator and denominator that user entered
		return;
}

void stern_brocot::print(void) //function to print the stern-brocot tree
{
	while (list3.empty() == false) //until list3 becomes empty, print and pop
	{
		int i = 0;
		while (list3.front().empty() == false) //until one level of the tree becomes empty
		{
			if (i % 2 != 0) //because we only have to print the new nodes of that level, not the original ones
				cout << list3.front().front().first << "/" << list3.front().front().second << "  ";
			list3.front().pop_front();
			i++;
		}
		list3.pop_front(); //change the level of the tree
		cout << endl;
	}
}

void stern_brocot::findLR(void) //function to print the path of fraction
{
	int div = list2.size() / 2;
	while (div > 1)
	{
		div /= 2;
		if (user_index <= div)
			cout << "L";
		else
		{
			cout << "R";
			user_index -= div; //move the user_index, to the left side of div
		}
	}
}
