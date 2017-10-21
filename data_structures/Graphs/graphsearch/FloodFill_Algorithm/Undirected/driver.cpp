#include "UndirectedGraph.hpp"
#include <cstring>
#include <string>
#include <fstream>

void work(int& i)
 {
cout<<" "<<i<<" ";
 }

int main(int argc, char *argv[])
{
	int num=0,k;
if(argc==3) 
{
	string fname=argv[1];
	char mode=argv[2][0];
	//cout<<fname
	string line;
    ifstream myfile;
    myfile.open(fname.c_str());


    if(myfile.is_open())
    {
        while(!myfile.eof())
        {
            getline(myfile,line);
            //cout<< line << endl;
            num++;
        }
        num--;
        myfile.close();
        UndirectedGraph g(num,mode);
        myfile.open(fname.c_str());

        for(int i=0;i<num;i++)
        {
          	for(int j=0;j<num;j++)
          	{
          		myfile>>k;
          		if(k) g.add(i,j,k);
          	}
          	//cout<<endl;	
        }
        myfile.close();
        //cout<<g.edges();
        cout<<endl;
        g.print();
        cout<<endl;
        int c,t1,t2,t3;
        while(1)
        {

          cout<<"1. Number of Edges"<<endl;
          cout<<"2. Number of Vertices"<<endl;
          cout<<"3. Check if edge exists between given vertices"<<endl;
          cout<<"4. Print Graph(Adjacency List or Adjacency Matrix)"<<endl;
          cout<<"5. Add edge between given vertices"<<endl;
          cout<<"6. Remove edge between given vertices"<<endl;
          cout<<"7. BFS from a given vertex"<<endl;
          cout<<"8. DFS from a given vertex"<<endl;
          cout<<"9. Degree of a given vertex"<<endl;
          cout<<"10. Exit"<<endl<<"UndirectedGraph << ";

          cin>>c;

          switch(c)
          {
            case 1:cout<<"\nNumber of Edges : "<<g.edges()<<endl<<endl;
                  break;
            case 2:cout<<"\nNumber of Vertices : "<<g.vertices()<<endl<<endl;
                  break;
            case 3:
                  cout<<"\nEnter Source Vertex : ";
                  cin>>t1;
                  cout<<"\nEnter Destination Vertex : ";
                  cin>>t2;
                  if( t1<g.vertices() && t2<g.vertices() && g.edgeExists(t1,t2) )
                    cout<<"\nEdge Exists between "<<t1<<" and "<<t2<<endl<<endl;
                  else cout<<endl<<"Edge Does not Exist"<<endl<<endl;
                  break;                              
            case 4:cout<<endl;
                   g.print();
                   cout<<endl;
                  break;                  
            case 5:cout<<"\nEnter Source Vertex : ";
                  cin>>t1;
                  cout<<"\nEnter Destination Vertex : ";
                  cin>>t2;
                  cout<<"\nEnter Weight: ";
                  cin>>t3;
                  if( t1<g.vertices() && t2<g.vertices() )
                      {
                        g.add(t1,t2,t3);
                        cout<<"\nEdge between "<<t1<<" and "<<t2<<" added"<<endl<<endl;
                      }
                  break;
            case 6:cout<<"\nEnter Source Vertex : ";
                  cin>>t1;
                  cout<<"\nEnter Destination Vertex : ";
                  cin>>t2;
                      if( t1<g.vertices() && t2<g.vertices() )
                      {
                        g.remove(t1,t2);
                        cout<<"\nEdge between "<<t1<<" and "<<t2<<" removed"<<endl<<endl;
                      }
                  break;
            case 7:cout<<"\nEnter Source Vertex : ";
                  
                  cin>>t1;
                  if(t1<g.vertices())
                  {
                  cout<<"The BFS from vertex "<<t1<<" is as follows"<<endl;
                  g.bfs(&work,t1);
                  }cout<<endl;
                  break;
            case 8:cout<<"\nEnter Source Vertex : ";
                  
                  cin>>t1;
                  if(t1<g.vertices())
                  {                  
                  cout<<"The DFS from vertex "<<t1<<" is as follows"<<endl;
                  LinearList<DFSNode> arr(g.vertices());
                  arr=g.dfs(&work,t1);
                  cout<<endl;

                  LinearList< list<int> > predetree(g.vertices());
                    for(int i=0;i<g.vertices();i++)
                    {
                      if(arr[i].pred!=-1) predetree[arr[i].pred].append(i);
                    }
                  cout<<endl;
                  for(int i=0;i<g.vertices();i++)
                    {
                      cout<<i<<" : ";
                      listnode<int> *tmp=predetree[i].first;
                      while ( tmp!= NULL ) 
                      {   
                        cout<<tmp->getdata()<<" ";
                        tmp = tmp->getlink();
                      };
                        cout<<endl;
                      }
                    }

                  break;
            case 9:cout<<"\nEnter Vertex : ";
                  cin>>t1;
                  if(t1<g.vertices())
                  cout<<"\nThe degree of vertex "<<t1<<" is "<<g.degree(t1)<<" ."<<endl<<endl;
                  break;
            case 10:return 0;

            default:cout<<"\nInvalid Choice\n"<<endl;
                  break;
          }
        }
    }
}

  else if(argc==2)
  {
      char mode=argv[1][0];
    	cout<<"Enter Number of Vertices : ";
    	cin>>num;
    	UndirectedGraph g(num,mode);
    	cout<<"Enter Adjacency Matrix \n ";
    	for(int i=0;i<num;i++)
        {
        for(int j=0;j<num;j++)
            {
                cin>>k;
                if(k)
                 g.add(i,j,k);
            }      	
              		
        }
        cout<<endl;
        g.print();
        cout<<endl;

        int c,t1,t2,t3;
        while(1)
        {

          cout<<"1. Number of Edges"<<endl;
          cout<<"2. Number of Vertices"<<endl;
          cout<<"3. Check if edge exists between given vertices"<<endl;
          cout<<"4. Print Graph(Adjacency List or Adjacency Matrix)"<<endl;
          cout<<"5. Add edge between given vertices"<<endl;
          cout<<"6. Remove edge between given vertices"<<endl;
          cout<<"7. BFS from a given vertex"<<endl;
          cout<<"8. DFS from a given vertex"<<endl;
          cout<<"9. Degree of a given vertex"<<endl;
          cout<<"10. Exit"<<endl<<"UndirectedGraph << ";

          cin>>c;

          switch(c)
          {
            case 1:cout<<"\nNumber of Edges : "<<g.edges()<<endl<<endl;
                  break;
            case 2:cout<<"\nNumber of Vertices : "<<g.vertices()<<endl<<endl;
                  break;
            case 3:
                  cout<<"\nEnter Source Vertex : ";
                  cin>>t1;
                  cout<<"\nEnter Destination Vertex : ";
                  cin>>t2;
                  if( t1<g.vertices() && t2<g.vertices() && g.edgeExists(t1,t2) )
                    cout<<"\nEdge Exists between "<<t1<<" and "<<t2<<endl<<endl;
                  else cout<<endl<<"Edge Does not Exist"<<endl<<endl;
                  break;                              
            case 4:cout<<endl;
                   g.print();
                   cout<<endl;
                  break;                  
            case 5:cout<<"\nEnter Source Vertex : ";
                  cin>>t1;
                  cout<<"\nEnter Destination Vertex : ";
                  cin>>t2;
                  cout<<"\nEnter Weight : ";
                  cin>>t3;
                  if( t1<g.vertices() && t2<g.vertices() )
                      {
                        g.add(t1,t2,t3);
                        cout<<"\nEdge between "<<t1<<" and "<<t2<<" added"<<endl<<endl;
                      }
                  break;
            case 6:cout<<"\nEnter Source Vertex : ";
                  cin>>t1;
                  cout<<"\nEnter Destination Vertex : ";
                  cin>>t2;
                      if( t1<g.vertices() && t2<g.vertices() )
                      {
                        g.remove(t1,t2);
                        cout<<"\nEdge between "<<t1<<" and "<<t2<<" removed"<<endl<<endl;
                      }
                  break;
            case 7:cout<<"\nEnter Source Vertex : ";
                  
                  cin>>t1;
                  if(t1<g.vertices())
                  {
                  cout<<"The BFS from vertex "<<t1<<" is as follows"<<endl;
                  g.bfs(&work,t1);
                  }cout<<endl;
                  break;
            case 8:cout<<"\nEnter Source Vertex : ";
                  
                  cin>>t1;
                  if(t1<g.vertices())
                  {                  
                  cout<<"The DFS from vertex "<<t1<<" is as follows"<<endl;
                  LinearList<DFSNode> arr(g.vertices());
                  arr=g.dfs(&work,t1);
                  cout<<endl;

                  LinearList< list<int> > predetree(g.vertices());
                    for(int i=0;i<g.vertices();i++)
                    {
                      if(arr[i].pred!=-1) predetree[arr[i].pred].append(i);
                    }
                  cout<<endl;
                  for(int i=0;i<g.vertices();i++)
                    {
                      cout<<i<<" : ";
                      listnode<int> *tmp=predetree[i].first;
                      while ( tmp!= NULL ) 
                      {   
                        cout<<tmp->getdata()<<" ";
                        tmp = tmp->getlink();
                      }
                      cout<<endl;
                    }
                  }
                  cout<<endl;
                  break;
            case 9:cout<<"\nEnter Vertex : ";
                  cin>>t1;
                  if(t1<g.vertices())
                  cout<<"\nThe degree of vertex "<<t1<<" is "<<g.degree(t1)<<" ."<<endl<<endl;
                  break;
            case 10:return 0;

            default:cout<<"\nInvalid Choice\n"<<endl;
                  break;
          }
        }


  }
	return 0;
}
