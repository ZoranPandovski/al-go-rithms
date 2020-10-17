#include <iostream>
using namespace std;

int sellWinesRecusive(int i,int j,int p[],int y)
{
    if(i > j)
    {
        return 0;
    }
    
    int op1 = p[i]*y + sellWinesRecusive(i + 1,j,p,y + 1);
    int op2 = p[j]*y + sellWinesRecusive(i,j - 1,p,y + 1);
    
    return max(op1,op2);
}

int sellWinesTD(int i,int j,int dp[][100],int p[],int y)
{
    if(i>j)
    {
        return 0;
    }
    
    if(dp[i][j] != 0)
    {
        return dp[i][j];
    }
    
    int op1 = p[i]*y + sellWinesTD(i + 1,j,dp,p,y + 1);
    int op2 = p[j]*y + sellWinesTD(i,j - 1,dp,p,y + 1);
    
    return dp[i][j] = max(op1,op2);
}

int sellWinesBU(int p[],int n)
{
    int dp[n][n] = {0};
    
    for(int i=0 ; i<n ; i++)
    {
        dp[i][i] = p[i]*n;
    }
    
    int year = n - 1;
    
    for(int gap=1 ; gap<n ; gap++)
    {
        for(int i=0,j=i+gap ; j<n ; i++,j++)
        {
            int op1 = p[j]*year + dp[i][j-1];
            int op2 = p[i]*year + dp[i+1][j];
            dp[i][j] = max(op1,op2);
        }
        year--;
    }
    
    return dp[0][n-1];
}


int main()
{
    int n;
    cin>>n;
    int p[n];
    
    for(int i=0 ; i<n ; i++)
    {
        cin>>p[i];
    }
    
    //Recursive Approach
    cout<<sellWinesRecusive(0,n-1,p,1);
    cout<<endl;
    
    //DP Bottom Up Approach
    cout<<sellWinesBU(p,n)<<endl;
    
    //DP Top Down Approach
    int dp[100][100] = {0};
    int y = 1;
    cout<<sellWinesTD(0,n-1,dp,p,y);
    cout<<endl<<endl;
    
    return 0;
}
