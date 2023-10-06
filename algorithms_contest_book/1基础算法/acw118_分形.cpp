#include<iostream>
using namespace std;
const int N= 1000;
char g[N][N];
void dfs(int n)
{
    if(n==1)
    {
        g[0][0]='X';
        return;
    }
    dfs(n-1);
    int len=1;
    for(int i=0;i<n-2;i++)
    len*=3;
    int sx[]={0,1,2,2},sy[]={2,1,0,2};
    for(int k=0;k<4;k++)
    {
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<len;j++)
            {
                g[sx[k]*len+i][sy[k]*len+j]=g[i][j];
            }
        }
    }
}
int main()
{
    dfs(7);
    int n;
    while(cin>>n,n!=-1)
    {
        int k=1;
        while(--n)k*=3;
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                if(g[i][j])cout<<g[i][j];
                else cout<<' ';
            }
            cout<<endl;
        }
        cout<<'-'<<endl;
    }
}