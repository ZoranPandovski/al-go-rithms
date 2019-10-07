#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[9] = { 1, 4, 2, 3, 8, 3, 4, 1, 9};		// LIS should be {1, 2, 3, 8, 9}
   	int	f[9] = {}, LIS[9] = {}, max = 1, L = 0;		// f used to record previous location of LIS
    for (int i = 0; i < 9; i++)
    {
        LIS[i] = 1;
        f[i] = i;
    }
    for (int i = 1; i < 9; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (arr[j] < arr[i] && LIS[j]+1 > LIS[i])
            {
                LIS[i] = LIS[j] + 1;
                if (LIS[i] > max)
				{
					max = LIS[i];
					L = i;
				}
                f[i] = j;
            }
        }
    }
	int tmp = L;
	while(LIS[L]--)
	{
		cout << arr[tmp] << " ";
		tmp = f[tmp];
	}	
    cout << endl;
    return 0;
}
