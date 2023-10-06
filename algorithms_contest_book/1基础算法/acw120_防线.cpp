#include<iostream>
using namespace std;
const int N =2e5+10;
typedef long long ll;
struct seq
{
    ll s,e,d;
};
seq a[N];
int n,t;
ll get_sum(ll x)
{
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        if(a[i].s>x)continue;
        else
        ans+=(min(x,a[i].e)-a[i].s)/a[i].d+1;
    }
    return ans;
}
int main()
{
    scanf("%d",&t);
    while(t--) 
    {
        scanf("%d",&n);
        ll l=0,r=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld%lld",&a[i].s,&a[i].e,&a[i].d);
            r=max(r,a[i].e);
        }
        while(l<r)
        {
            ll mid=(l+r)>>1;
            if(get_sum(mid)&1)r=mid;
            else l=mid+1;
        }
        ll ans=get_sum(l)-get_sum(l-1);
        if(ans&1)
        printf("%lld %lld\n",l,ans);
        else
        puts("There's no weakness.");
    }
    return 0;
}