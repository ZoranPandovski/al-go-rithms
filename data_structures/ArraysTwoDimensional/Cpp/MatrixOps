#include<iostream>
using namespace std;
int main()
{
    float mat[10][3];
    //float max=0,min=999;
    cout<<"Enter the matrix";
    for(int i=0;i<10;i++)
        for(int j=0;j<3;j++)
            cin>>mat[i][j];
    for(int k=0;k<3;k++)
    {
        float max=0;
    for(int l=0;l<10;l++)
    {
        if(max<mat[l][k])
            max=mat[l][k];
    }
    cout<<"MAX OF "<<k<<" COLUMN "<<max<<endl;
    }
    for(int k=0;k<3;k++)
    {
        float min=999;
    for(int l=0;l<10;l++)
    {
        if(min>mat[l][k])
            min=mat[l][k];
    }
    cout<<"MIN OF "<<k<<" COLUMN "<<min<<endl;
    }
    for(int i=0;i<3;i++)
    {
        cout<<"MIDRANGE OF "<<i<<" COLUMN "<<
    }
    for(int k=0;k<3;k++)
    {
        float sum=0;
        for(int l=0;l<10;l++)
        {
            sum+=mat[l][k];
        }
        float mean=sum/10;
        cout<<"MEAN OF "<<k<<" COLUMN "<<mean<<endl;
    }

    for(int i=0;i<3;i++)
    {
        for(int k=0;k<10-1;k++)
        {
            for(int j=k+1;j<10;j++)
            {
            if(mat[k][i]>mat[j][i])
            {
                int temp=mat[k][i];
                mat[k][i]=mat[j][i];
                mat[j][i]=temp;
            }

            }
        }
    }
    for(int j=0;j<3;j++)
    {
        float median=(mat[5][j]+mat[6][j])/2;
            cout<<"MEDIAN OF "<<j<<" COLUMN "<<median<<endl;
        //cout<<endl;
    }
    for(int j=0;j<3;j++)
    {
        int mode=-999,c=0;float p;
        for(int k=0;k<10;k++)
        {
            while(mat[k][j]==mat[k+1][j])
            {
                    c++;
                    k++;
            }
            if(mode<c)
            {
                mode=c;
                p=mat[k][j];
            }
        }
        cout<<"MODE OF "<<j<<" COLUMN "<<p<<endl;
    }


}
