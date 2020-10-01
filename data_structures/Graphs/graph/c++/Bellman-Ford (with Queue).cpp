/// this is the Bellman-Ford algorithm for finding the costs of going from a starting node to any other and it can be used even when the costs are negative
/// the algorithm can also detect if the graph has negative cycles, it also presents an optimization which makes it better in practice than Dijkstra with the heap optimization and way easier to implement
/// the optimization is done by using a queue and trying to use as intermediate nodes only those which have been updated, not every node

/*   test
5 8
1 3 -3
1 5 7
3 2 -2
3 4 7
5 1 4
5 2 3
5 3 4
4 5 3
*/
#include <fstream>
#include <cstdio>
#define infi 1<<30

using namespace std;

ofstream fout("bellmanford.out");

int n,que[50005],Q[500005],C[50005],viz[50005],OK;

struct nod{   /// we keep the graph using a dynamic adjacency list
    nod *urm; ///pointer to the next node
    int inf,cost; ///integers that keep the current node and it's cost
}*L[50001]; ///we set the dimension of the pointer vector with 1 more than the maximum number of possible nodes
            ///L[x] is a list with all the neighbours of x

inline void add(int &a, int &b, int &c){ ///we add the new edge to the list, adding a new node to the adjacency list will be done
    nod *p=new nod; /// by moving the start of the list, so we don't have to traverse the whole neighbours list
    p->inf=b;
    p->cost=c;
    p->urm=L[a];
    L[a]=p;
}

void bell(int k){
    int p,u,q;
    nod *vec;
    Q[1]=k; /// we put the first element into the queue
    p=u=1;
    que[1]=1;
    while(p<=u){ ///while we have elements in the queue
        q=Q[p++]; /// take the first
        viz[q]++; ///mark it as visited
        if(viz[q]>n){ /// if we have visited it more than the number of nodes, then we have a negative cycle
            OK=1;
            break;
        }
        vec=L[q];
            while(vec){ ///we try to optimize the cost of every neighbour using this node as intermediate
                if(C[vec->inf]>vec->cost+C[q]){
                    C[vec->inf]=vec->cost+C[q]; ///we update the cost
                    if(!que[vec->inf]) /// and if the neighbour is not already in the processing queue, we put it there
                        que[vec->inf]=1,Q[++u]=vec->inf;
                }
                vec=vec->urm;
            }
    que[q]=0;///and we mark that the current node is no longer in the processing queue
    }

    if(OK==0)
        for(int i=2;i<=n;i++)
            fout<<C[i]<<' ';
    else
        fout<<"Negative Cycle!";
}

int main()
{
    int i,a,b,c,m;
    FILE*fin=freopen("bellmanford.in","r",stdin); /// we open our input folder which contains a directed graph. The folder needs to have the following structure:
    /// n(number of nodes) m(number of edges) followed by m lines of the following form:
    /// x (start node for this edge) y (destination node for this edge) c (cost of the edge)

    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c); /// we add the directed edge to the adjacency list
                    /// because the graph is directed, we only call add once, if it was undirected, we just had to call add(b,a,c) to put the way back
    }

    for(int i=2;i<=n;i++)
        C[i]=infi; ///we set a very big cost to each node except the start one

    bell(1); /// we start from the starting node, which is 1 in this case
    return 0;
}
