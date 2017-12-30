//k-means clustering for tabular data having different attributes
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int n, nAttr, nClusters;
	cout<<"Enter number of entries, attributes and clusters : ";
	cin>>n>>nAttr>>nClusters;

	vector< vector<double>> entries(n, vector<double>(nAttr));	

	//Read data about objects
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<nAttr; j++)
		{
			cin>>entries[i][j];
		}
	}

	//To stor cluster centroids
	vector< vector<double>> cluster(nClusters, vector<double>(nAttr));	

	//Read data about centroids of clusters
	cout<<"Enter centroids of "<<nClusters<<" clusters : ";
	for(int i=0; i<nClusters; i++)
	{
		for(int j=0; j<nAttr; j++)
		{
			cin>>cluster[i][j];
		}
	}

	vector<vector<double>> oldCluster = cluster;

	//To classify objects to clusters
	vector<int> groups(n);

	do
	{
		for(int i=0; i<n; i++)	//For each object
		{
			vector<double> dist(nClusters, 0);

			cout<<"For object : "<<i<<endl;
			for(int c=0;c<nClusters; c++)	//For each cluster
			{
				double tempdist = 0;
				for(int j=0; j<nAttr; j++)	//For each attribute
				{
					tempdist += pow((entries[i][j] - cluster[c][j]), 2);
				}
				
				dist[c] = sqrt(tempdist);
			}

			int minidx = 0;

			for(int k=0; k<nClusters; k++)
			{
				cout<<"Cluster : "<<k<<" DIstance : "<<dist[k]<<endl;
				if(dist[k] < dist[minidx])
				{
					minidx = k;
				}
			}

			groups[i] = minidx;
		}
		
		vector<int> count(nClusters, 0);	//To store count of objects in each cluster
		for(int i=0; i<n; i++)
		{
			count[groups[i]]++;
		}

		oldCluster = cluster;

		//Reset new cluster to 0
		for(int i=0; i<nClusters; i++)
		{
			for(int j=0; j<nAttr; j++)
			{
				cluster[i][j] = 0;
			}
		}

		//Calculate new centroid for each cluster
		for(int i=0; i<n; i++)
		{
			int clusterno = groups[i];
			for(int j=0; j<nAttr; j++)
			{
				cluster[clusterno][j] += entries[i][j];
			}
		}

		for(int i=0; i<nClusters; i++)
		{
			for(int j=0; j<nAttr; j++)
			{
				cluster[i][j] /= count[i];
			}
		}

	}while(oldCluster != cluster);
	
	for(int i=0; i<n; i++)
	{
		cout<<"Group "<<i<<" == "<<groups[i]<<endl;
	}

	//Old cluster
	for(int i=0; i<nClusters; i++)
	{
		for(int j=0; j<nAttr; j++)
		{
			cout<<oldCluster[i][j]<<"\t";
		}
		cout<<endl;
	}

	cout<<"New cluster "<<endl;
	//New Cluster
	for(int i=0; i<nClusters; i++)
	{
		for(int j=0; j<nAttr; j++)
		{
			cout<<cluster[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	return 0;
}

