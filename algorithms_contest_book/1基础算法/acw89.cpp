#include<iostream>
using namespace std;
typedef long long ll;
ll power(ll a,ll b, ll p)
{
    ll ans=1%p;
    for(;b;b>>=1)
    {
        if(b&1)ans=ans*a%p;
        a=a*a%p;
    }
    return ans;
}
int main()
{
    ll a,b,p;
    cin>>a>>b>>p;
    cout<<power(a,b,p)<<endl;
    return 0;
}