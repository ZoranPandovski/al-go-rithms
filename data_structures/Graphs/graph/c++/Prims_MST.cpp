#include <bits/stdc++.h>

#define NO_OF_NODES 8

using namespace std;


struct node
{
    int fr, to, cost;
}p[6];

int c = 0, temp1 = 0, temp = 0;

void prims(int *a, int b[][NO_OF_NODES], int i, int j)
{
    a[i] = 1;
    while (c < 6)
    {
        int min = 999;
        for (int i = 0; i < NO_OF_NODES; i++)
        {
            if (a[i] == 1)
            {
                for (int j = 0; j < NO_OF_NODES; )
                {
                    if (b[i][j] >= min || b[i][j] == 0)
                    {
                        j++;
                    }
                    else if (b[i][j] < min)
                    {
                        min = b[i][j];
                        temp = i;
                        temp1 = j;
                    }
                }
            }
        }
        a[temp1] = 1;
        p[c].fr = temp;
        p[c].to = temp1;
        p[c].cost = min;
        c++;       
        b[temp][temp1] = b[temp1][temp]=1000;
    }
    for (int k = 0; k < NO_OF_NODES-1; k++)
    {
        cout<<"Source node: "<<p[k].fr<<endl;
        cout<<"Destination node: "<<p[k].to<<endl;
        cout<<"Weight of node: "<<p[k].cost<<"\n\n";
    }
}

int main()
{   int a[NO_OF_NODES];
    for (int i = 0; i < NO_OF_NODES; i++)
    {
        a[i] = 0;
    }
    int b[NO_OF_NODES][NO_OF_NODES];
    for (int i = 0; i < NO_OF_NODES; i++)
    {
        cout<<"enter values for "<<(i+1)<<" row"<<endl;
        for (int j = 0; j < NO_OF_NODES; j++)
        {
            cin>>b[i][j];
        }
    }
    prims(a, b, 0, 0);
    
    return 0;
}