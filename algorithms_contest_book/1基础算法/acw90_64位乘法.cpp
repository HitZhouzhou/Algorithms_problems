#include<iostream>
using namespace std;
typedef long long ll;
ll a,b,p;
ll mul(ll a,ll b,ll p)
{
    ll ans=0;
    for(;b;b>>=1)
    {
        if(b&1)ans=(ans+a)%p;
        a=(a*2)%p;
    }
    return ans;
}
int main()
{
    cin>>a>>b>>p;
    cout<<mul(a,b,p)<<endl;
    return 0;
}