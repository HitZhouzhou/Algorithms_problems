#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 5e4 + 10;
typedef long long ll;
ll n,ans=-0x3f3f3f3f,sum[N];
struct cow
{
    ll w, s;
    bool operator<(const cow &x)const
    {
        return max(-s,w-x.s)<=max(-x.s,x.w-s); 
    }
}cows[N];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        ll w,s;
        cin>>w>>s;
        cows[i].w=w,cows[i].s=s;
    }
    sort(cows+1,cows+1+n);
    for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+cows[i].w;
    }
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,sum[i-1]-cows[i].s);
    }
    cout<<ans<<endl;
    return 0;
}