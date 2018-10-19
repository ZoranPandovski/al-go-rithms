#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	printf("Enter number of processes:");
	scanf("%d", &n);
	int arrival[n];
	int burst[n];
	int completion[n];
	int turn[n];
	int waiting[n];
	printf("Enter arrival and burst time of %d processes:\n", n);
	queue <int> q;
	for(int i = 0; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		arrival[i] = u;
		burst[i] = v;
		q.push(i);
	}
	int tq;
	printf("Enter time quantum:");
	scanf("%d", &tq);
	int completion_t = 0;
	int first = q.front();
	q.pop();
	if(burst[first] <= tq)
	{
		completion[first] = burst[first];
		completion_t = burst[first];
	}
	else
	{
		q.push(first);
		completion_t = tq;
		burst[first] -= tq;
	}
	while(!q.empty())
	{
		int current = q.front();
		q.pop();
		if(burst[current] <= tq)
		{
			completion[current] = burst[current] + completion_t;
			completion_t += burst[current];
		}
		else
		{
			q.push(current);
			burst[current] -= tq;
			completion_t += tq;
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		turn[i] = completion[i] - arrival[i];
		waiting[i] = turn[i] - burst[i];
	}
	for(int i = 0; i < n; i++)
		printf("%d %d %d\n", completion[i], turn[i], waiting[i]);
}
