#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N =1e6+100;
ll a[N],n,s;
int main()
{
    cin>>n;
    
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    ll x=s/n;
    for(int i=1;i<=n;i++)
    {
        a[i]-=x;
        a[i]+=a[i-1];
    }
    sort(a+1,a+1+n);
    if(n&1)
    x=a[(n+1)/2];
    else
    x=a[n/2];
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=abs(a[i]-x);
    }
    cout<<ans<<endl;
    return 0;
}