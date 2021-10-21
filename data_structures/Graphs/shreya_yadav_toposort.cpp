#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define pb push_back

using namespace std;

int main()
{
	
	int n = 5, edges = 10; // nodes are numbered 0,1,2,3,4;

	vector<int> adjacency_list[5], result, in_degree(n, 0);
	queue<int> q;

	/*	Graph representation in adjacency list: (feel free to input your own graph)
		0 -> 2, 3, null
		1 -> 2, null
		2 -> 3, 4, null
		3 -> null
		4 -> null 

		The topological sort order for this graph is 0, 1, 2, 3, 4 OR 1, 0, 2, 3, 4 etc.
	*/

	adjacency_list[0].pb(2);		
	adjacency_list[0].pb(3);		
	adjacency_list[1].pb(2);	
	adjacency_list[2].pb(3);	
	adjacency_list[2].pb(4);	
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<adjacency_list[i].size();j++)
		{
			int node = adjacency_list[i][j];
			in_degree[node]++;
		}
	}	

	for(int i=0;i<n;i++)
	{
		if(in_degree[i] == 0)
			q.push(i);
	}

	while(!q.empty())
	{
		int current_node = q.front();
		result.pb(current_node);
		q.pop();
		for(int i=0;i<adjacency_list[current_node].size();i++)
		{
			in_degree[adjacency_list[current_node][i]]--;
			if(in_degree[adjacency_list[current_node][i]] == 0)
				q.push(adjacency_list[current_node][i]);
		}
	}


	if(result.size() == n)
	{
		for(int i=0;i<n;i++)
		{
			cout<<result[i]<<" ";
		}
		cout<<endl;
	}
	else
	{
		cout<<"There exists a cycle in the graph"<<endl;
	}

	/* 	alternatively you can check for a cycle by checking the in-degrees
		bool cycle = false;
		for(int i=0;i<n;i++)
		{
			if(in_degree[i] != 0)
			{
				cycle = true;
			}
		} 
	*/
	return 0;
}
