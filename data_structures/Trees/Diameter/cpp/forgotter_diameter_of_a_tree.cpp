//C++ program to find diameter of a tree in O(n)
//Idea is to first pick any arbitary vertice and run a dfs on 
//the input tree, and choose any one vertice having maximum distance
//as one of end of diameter. Run another dfs but this time from
//the choosen end vertice, and again choose the vertice at maximum
//distance as another end. Thus we have both the end vertices of diameter
//the path is found out by running a dfs from any of the end vertice

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TreeDiameter
{
public:
	int SIZE;
	vector< vector< int > >arr;
	vector< int >depth;
	vector< int >diameter_path;

	//TreeDiameter can be initialzed using only no of vertices
	//and then adding the edges manually in code
	TreeDiameter(int size)
	{
		SIZE = size;
		arr.resize(SIZE);
		depth.resize(SIZE);
	}

	//TreeDiameter can be initialized by adjacency list
	TreeDiameter(vector< vector<int> >& tree)
	{
		SIZE = tree.size();
		arr = tree;
		depth.resize(SIZE);
	}

	//dfs utility
	void dfs(int from, int to)
	{
		depth[to] = depth[from]+1;
		for(auto x:arr[to])
		{
			if(x!=from)
				dfs(to,x);
		}
	}

	//utility to find path to given vertice
	void add_path(int from, int to, int last, vector<int>& v)
	{
		if(diameter_path.size() > 0) return;

		v.push_back(to);
		if(to == last)
		{
			diameter_path.resize(v.size());
			for(int i=0;i<v.size();i++) diameter_path[i]=v[i];
			return;
		}

		for(auto x:arr[to])
		{
			if(x!=from)
				add_path(to,x,last,v);
		}
		v.pop_back();
	}

	//find the end vertices of diameter and then finds the path between them
	void get_diameter()
	{
		int leaf1,leaf2;
		dfs(0,1);
		leaf1 = max_element(depth.begin(),depth.end())-depth.begin();
		dfs(0,leaf1);
		leaf2 = max_element(depth.begin(),depth.end())-depth.begin();

		vector<int>v;
		add_path(0, leaf1, leaf2, v);
	}
};

int main()
{
	//n is the no of vertices in the tree
	int n,u,v;
	cin>>n;

	//store the edges in an adjancency list
	vector< vector<int> > arr(n+1);
	for(int i=1; i<n; i++)
	{
		cin>>u>>v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}

	//create an object of TreeDiameter
	TreeDiameter tree(arr);

	//find the diameter of tree
	tree.get_diameter();

	//pinting the vertices lying along the diamater
	for(int i=0; i<tree.diameter_path.size(); i++)
		cout<<tree.diameter_path[i]<<" ";
}