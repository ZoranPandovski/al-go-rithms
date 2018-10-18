/// CYCLE DETECTION IN A GRAPH
/// AUTHOR: SHAHIDCSEKU
#include<stdio.h>
#define nNodes 3
int G[nNodes][nNodes],S[nNodes];
int dfs(int i)
{
    //printf("%d\n",i);
    S[i]=1;
    for(int j=0;j<nNodes;j++)
    {
        if(!S[j] && G[i][j]==1)
        {
            /// Visited and has child then recursion

            dfs(j);
        }
        if(S[j])
        {
            printf("Cycle Found\n");
            return 0;
        }
    }
}
int main()
{
    printf("Enter adjacency matrix[%dx%d]:\n",nNodes,nNodes);
    for(int i=0;i<nNodes;i++)
    {
        for(int j=0;j<nNodes;j++)
        {
            scanf("%d",&G[i][j]);
        }
        /// Visited =0;
        S[i] = 0;
    }
    dfs(5);
}

/*
*/
