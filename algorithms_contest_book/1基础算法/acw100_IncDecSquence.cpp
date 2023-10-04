#include<iostream>
#include<math.h>

using namespace std;
const int N =1e5+10;
typedef long long ll;
ll a[N],b[N];
ll n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    ll q=0,p=0;
    for(int i=2;i<=n;i++)
    {
        b[i]=a[i]-a[i-1];
        if(b[i]<0)q+=-b[i];
        if(b[i]>0)p+=b[i];
    }
    printf("%lld\n%lld\n",max(p,q),abs(q-p)+1);
}