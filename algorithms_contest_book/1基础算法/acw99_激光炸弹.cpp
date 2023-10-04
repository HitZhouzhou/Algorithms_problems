#include <iostream>
using namespace std;
const int N = 5e3 + 10;
typedef int ll;
ll s[N][N];
ll n, r;
int main()
{
    cin >> n >> r;
    r=min(r,5001);
    for (int i = 0; i < n; i++)
    {
        ll x,y,w;
        cin>>x>>y>>w;
        s[x+1][y+1]+=w;
    }
    for(int i=1;i<=N-9;i++)
    {
        for(int j=1;j<=N-9;j++)
        {
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+s[i][j];
        }
    }
    int ans=0;
    for(int i=r;i<=N-9;i++)
    {
        for(int j=r;j<=N-9;j++)
        {
            ans=max(ans,s[i][j]-s[i-r][j]-s[i][j-r]+s[i-r][j-r]);
        }
    }
    cout<<ans<<endl;
}