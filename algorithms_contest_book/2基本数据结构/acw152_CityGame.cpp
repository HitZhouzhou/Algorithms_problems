#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
const int N =1010;
char g[N][N];
int f[N][N];
int n,m;
typedef long long LL;
int get_max(int *a)
{
    stack<int>stk;
    stack<int>w;
    stk.push(0);
    w.push(0);
    a[m+1]=0;
    int ans=0;
    for(int i=1;i<=m+1;i++)
    {
        if(stk.top()<a[i])
        {
            stk.push(a[i]);
            w.push(1);
        }
        else
        {
            int width=0;
            while(stk.top()>a[i])
            {
                width+=w.top();
                w.pop();
                ans=max(ans,width*stk.top());
                stk.pop();
            }
            stk.push(a[i]);
            w.push(width+1);
        }
    }
    return ans;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        cin>>g[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(g[i][j]=='F')
            {
                f[i][j]=f[i-1][j]+1;
            }
            else
            {
                f[i][j]=0;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,get_max(f[i]));
    }
    cout<<ans*3<<endl;
    return 0;
}