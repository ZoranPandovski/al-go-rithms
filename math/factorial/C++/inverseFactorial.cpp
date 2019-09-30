#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <cstdint>

using namespace std;

int main()
{
	string input = "";

	cin >> input;

	const uint64_t numDigits = input.size();

	if(numDigits < 10)
	{
		uint64_t i = 1;
		uint64_t ans = 1;

		while(true)
		{
			ans *= i;

			if(ans == stoi(input))
			{
				cout << i;
				break;
			}

			i++;
		}
	}
	else
	{
		uint64_t i = 1;
		double ans = 1;

		while(true)
		{
			ans += log10(i);

			if(floor(ans) == numDigits)
			{
				cout << i;
				break;
			}

			i++;
		}
	}

	return 0;
}
