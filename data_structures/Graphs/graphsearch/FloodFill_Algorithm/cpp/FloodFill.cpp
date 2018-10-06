#include "Undirected/UndirectedGraph.hpp"
#include <cstdlib>
void work(int& i)
 {
//cout<<" "<<i<<" ";
 }

int main(int argc, char *argv[])
{
  srand(time(NULL));
  bool not_found=false;
  int n,m,num_x,src,dest;
  pair<int,int> s,d,x;
  int dirx[]={-1,0,1};
  int diry[]={0,1,-1};
  cout<<"Enter Number of rows : ";
  cin>>n;
  cout<<"Enter number of columns : ";
  cin>>m;

s=make_pair(0,0);
d=make_pair(0,0);
cout<<"Enter the Maze :\n";

  char a[n+2][m+2],t;
  UndirectedGraph g(n*m , 'l');
  
  for(int i=0;i<m+2;i++)
      {
        a[0][i]='X';  
        a[m+1][i]='X';
        a[i][0]='X';
        a[i][m+1]='X';
      }
  
  for(int i=1;i<=n;i++)
      {
      for(int j=1;j<=m;j++)
        {
        	cin>>a[i][j];
        	//cin>>t;
        	if(a[i][j]=='S') {s=make_pair(i,j);a[i][j]='O';}
        	else if(a[i][j]=='D') {d=make_pair(i,j);a[i][j]='O';}
        }
        //cin>>t;
      }

      		cout<<endl;
            cout<<endl;
      for(int i=1;i<=n;i++)
      {
      for(int j=1;j<=m;j++)
           {
           	if(i==s.first&&j==s.second) cout<<"S ";
           	else if (i==d.first&&j==d.second) cout<<"D ";
           	else cout<<a[i][j]<<" ";
           }

         cout<<endl;
      }
               cout<<endl;

      for(int i=n;i>=1;i--)
      {
      for(int j=m;j>=1;j--)
          {

            if(a[i][j]=='O') 
            {
                int sx=rand()%3,sy=rand()%3;
                for(int k=sx;k<sx+3;k++)
                  for(int l=sy;l<sy+3;l++)
                    {
                      //if(k%3==1 && l%3 == 1) continue;
                      int d1=i+dirx[k%3];
                      int d2=j+diry[l%3];
                      if(a[d1][d2]=='O') 
                      {
                        if((i-1)*m +(j-1) == (d1 - 1)*m + (d2 - 1))
                          continue;
                        g.add( (i-1)*m +(j-1) , (d1 - 1)*m + (d2 - 1) );
                      }

                    }
        
            } 
          
          }

      }
      src=(s.first-1)*m + (s.second-1);
      dest=(d.first-1)*m + (d.second-1);
      //g.print();
      LinearList<DFSNode> arr(n*m);
      arr=g.dfs(work,dest);
    /*  LinearList< list<int> > predetree(n*m);
      for(int i=0;i<n*m;i++){
      	if(arr[i].pred!=-1) predetree[arr[i].pred].append(i);
      		}
		cout<<endl;
      for(int i=0;i<n*m;i++)
      	{
      	cout<<i<<" : ";
		predetree[i].print();
		cout<<endl;
		} */     	
    int tmp=src;
    if(arr[tmp].pred==-1) 
    {
      cout<<"\n No path found\n";
      cout<<" END\n\n\n";
      return 0;
    }

      //cout<<tmp;
      while(tmp!=-1)
      {
        cout<<" ("<<tmp/m + 1 <<","<<tmp%m + 1<<") = >";
        if(tmp == dest) break;
        tmp=arr[tmp].pred;  
      }

      cout<<" END\n";
  

               cout<<endl;
               cout<<endl;

	return 0;
}
