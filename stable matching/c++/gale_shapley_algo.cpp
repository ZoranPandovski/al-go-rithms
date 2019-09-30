#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector <int> pref_men[n];
	int pref_women[n][n], pref_women1[n][n];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int x;
			scanf("%d", &x);
			pref_men[i].push_back(x);
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int x;
			scanf("%d", &x);
			pref_women1[i][j] = x;
			pref_women[i][x] = j;
		}
	}
	int couple_men[n], couple_women[n];
	queue <int> q;
	for(int i = 0; i < n; i++)
	{
		couple_men[i] = -1;
		couple_women[i] = -1;
		q.push(i);
	}
	while(!q.empty())
	{
		int current_man = q.front();
		q.pop();
		for(int j = 0; j < n; j++)
		{
			int current_woman = pref_men[current_man][j];
			if(couple_women[current_woman] == -1)
			{
				couple_women[current_woman] = current_man;
				couple_men[current_man] = current_woman;
				break;
			}
			else if(couple_women[current_woman] != -1)
			{
				int engaged_man = couple_women[current_woman];
				if(pref_women[current_woman][engaged_man] <= pref_women[current_woman][current_man])
				{
					continue;
				}
				else
				{
					couple_men[engaged_man] = -1;
					couple_men[current_man] = current_woman;
					couple_women[current_woman] = current_man;
					q.push(engaged_man);
					break;
				}
			}
		}
	}
	for(int i = 0; i < n; i++)
		printf("%d %d\n", i, couple_men[i]);
}
