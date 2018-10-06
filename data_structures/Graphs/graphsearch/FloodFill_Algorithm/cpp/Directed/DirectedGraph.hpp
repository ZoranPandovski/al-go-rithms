#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH 1
/*
 * A class to represent an UndirectedGraph
 * Subclasses AbstractGraph
 */
#include "../stack.hpp"
#include "../queue.hpp"

#include "../AdjacencyMatrix.hpp"
#include "../AdjacencyList.hpp"

#include "../AbstractGraph.hpp"



class DirectedGraph : AbstractGraph {

  private:AdjacencyMatrix graphm;
        AdjacencyList graphl;
        char repr;
        
 public:
  /*
   * Constructor: UndirectedGraph
   *
   * Parameters: mode
   * Used to decide which representation to use
   * 'm' for AdjacencyMatrix
   * 'l' for AdjacencyList
   */
  DirectedGraph(int vertices, char mode);

  bool edgeExists(int i, int j);

  void print();

  int edges();

  int vertices();

  void add(int i, int j, int w);

  void remove(int i, int j);

  LinearList<DFSNode> dfs(void (*work)(int&),int src);

  LinearList<BFSNode> bfs(void (*work)(int&),int src);

  int indegree(int i);

  int outdegree(int i);

};

DirectedGraph::DirectedGraph(int vertices, char mode)
{

    if(mode=='m') graphm.resAdjacencyMatrix(vertices);

    else if(mode=='l') graphl.resAdjacencyList(vertices);

    repr=mode;
    
}

  bool DirectedGraph::edgeExists(int i, int j)
  {
    if(repr=='m') return graphm.edgeExists(i,j);
    else return graphl.edgeExists(i,j);
  }

  int DirectedGraph::edges()
  {
    if(repr=='m') return graphm.edges();
    else return graphl.edges();
  } 

  int DirectedGraph::vertices()
  {
    if(repr=='m') return graphm.vertices();
    else return graphl.vertices();
  }

  void DirectedGraph::add(int i, int j, int w)
  {
    if(repr=='m') 
    {
      graphm.add(i,j,w);
    }
    else 
      {
        graphl.add(i,j,w);
      }
      
  }

  void DirectedGraph::remove(int i, int j)
  {
    if(repr=='m') 
      {
        graphm.remove(i,j);
      }
    else 
    {
      graphl.remove(i,j);
    }
    
  }


  LinearList<DFSNode> DirectedGraph::dfs(void (*work)(int&),int src)
  {

        int n=this->vertices(),time=0;
        LinearList<DFSNode> tree(n);

        for(int i=0;i<n;i++)
        {
          tree[i].col=WHITE;
          tree[i].pred=-1;
        }
        
        stack<int> s;
        s.push(src);
       
          while(!s.empty())
          {
             int i=s.top();
             if(tree[i].col==BLACK)
             {
              s.pop();
             }
             else if(tree[i].col==GRAY)
             {
              s.pop();
              tree[i].col=BLACK;
              time++;
              tree[i].ft=time;
             }
             else if(tree[i].col==WHITE)
             {
                 tree[i].col=GRAY;
                 work(i);
                 time++;
                 tree[i].dt=time;
               
                  if(repr=='m')
                  {
                       for(int j=0;j<n;j++)
                       {
                        if(this->edgeExists(i,j) && tree[j].col==WHITE ) 
                        {
                          s.push(j);
                          tree[j].pred=i;
                        }
                       }
                  }
                  else
                    {
                      listnode<pair<int,int> >* tmp=(graphl.AdjList()[i].getfirst());
                      while(tmp!=NULL)
                      {
                        int j=tmp->getdata().first;
                        if(tree[j].col==WHITE)
                        {
                          s.push(j);
                          tree[j].pred=i;
                        }
                        tmp=tmp->getlink();
                      }
                      
                    }
              }
            }

              for(int k=0;k<n;k++)
              {

              if(tree[k].col==WHITE)
              {
                s.push(k);
              }

             while(!s.empty())
             {
             int i=s.top();
            
                if(tree[i].col==BLACK) s.pop();
                
                else if(tree[i].col==GRAY)
                {
                s.pop();
                tree[i].col=BLACK;
                time++;
                tree[i].ft=time;
                  }
                
                else if(tree[i].col==WHITE)
                {
                    work(i);
                    tree[i].col=GRAY;
                    time++;
                    tree[i].dt=time;
       
       
                  if(repr=='m')
                  {
                       for(int j=0;j<n;j++)
                       {
                        if(this->edgeExists(i,j) && tree[j].col==WHITE ) 
                        {
                          s.push(j);
                          tree[j].pred=i;
                        }
                       }
                    }
                    else
                    {
                      listnode<pair<int,int> >* tmp=(graphl.AdjList()[i].getfirst());
                      while(tmp!=NULL)
                      {
                        int j=tmp->getdata().first;
                        if(tree[j].col==WHITE)
                        {
                          s.push(j);
                          tree[j].pred=i;
                      }
                        tmp=tmp->getlink();
                      }
                      
                    }


               }//cout<<"Finishing Time = "<<tree[i].ft<<endl;
            }

               }
              
              return tree;
  }

  LinearList<BFSNode> DirectedGraph::bfs(void (*work)(int&),int src)
  {

        int n=this->vertices();
        //Color col[n];
        //int pred[n];
        //int d[n];
        LinearList<BFSNode> tree(n);
        for(int i=0;i<n;i++)
        {
          tree[i].col=WHITE;
          tree[i].pred=-1;
          tree[i].d=0;

        }
        
        queue<int> q;
        q.push(src);
        tree[src].col=GRAY;
        work(src);
        //cout<<"Distance from Source = "<<tree[0].d<<" Predecessor NIL";
        //cout<<endl;

        while(!q.empty())
        {
         int i=q.pop();
         tree[i].col=BLACK; 
    if(repr=='m')
      {
          for(int j=0;j<n;j++)
          {
            if(this->edgeExists(i,j) && tree[j].col==WHITE) 
            {
              q.push(j);
              tree[j].col=GRAY;
              
              tree[j].d=tree[i].d+1;
              tree[j].pred=i;
            work(j);
            //cout<<"Distance from Source = "<<tree[j].d<<" Predecessor "<<tree[j].pred;
            //cout<<endl;
            }
          }
        }
        else
        {
          listnode<pair<int,int> >* tmp=(graphl.AdjList()[i].getfirst());
              while(tmp!=NULL)
              {
                int j=tmp->getdata().first;
                if(tree[j].col==WHITE)
                {
                  q.push(j);
                  tree[j].col=GRAY;
                  tree[j].d=tree[i].d+1;
                  tree[j].pred=i;
                  work(j);
                  //cout<<"Distance from Source = "<<tree[j].d<<" Predecessor "<<tree[j].pred;
                  //cout<<endl;
                }
                tmp=tmp->getlink();
              }
        }
         
        
        } 
    //cout<<endl;   
        return tree;
  }

  int DirectedGraph::outdegree(int i)
  {
    if(repr=='m') return graphm.outdegree(i);
    else return graphl.outdegree(i);
  }
  int DirectedGraph::indegree(int i)
  {
    if(repr=='m') return graphm.indegree(i);
    else return graphl.indegree(i);
  }
  void DirectedGraph::print()
  {
    if(repr=='m') graphm.print();
    else graphl.print();
  }


#endif /* ifndef UNDIRECTED_GRAPH */