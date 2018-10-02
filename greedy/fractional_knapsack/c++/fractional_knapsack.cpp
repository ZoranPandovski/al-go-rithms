#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num_items, capacity;
	printf("Enter number of items and capacity of sack:");
	scanf("%d%d", &num_items, &capacity);
	vector <pair <float, pair<int, int> > > vec;
	printf("Enter value and weight of each item:");
	for(int i = 0; i < num_items; i++)
	{
		int v, w;
		scanf("%d%d", &v, &w);
		vec.push_back(make_pair((float)v / w, make_pair(v, w)));
	}
	int item = 0;
	float max = 0;
	sort(vec.rbegin(), vec.rend());
	
	while(capacity)
	{
		if(vec[item].second.second <= capacity)
		{
			capacity -= vec[item].second.second;
			max += vec[item].second.first;
			item++;
		}
		else
		{
			float frac = (float) capacity / vec[item].second.second;
			max += ((float) vec[item].second.first * frac);
			item++;
			break;
		}
	}
	cout << max;
}
