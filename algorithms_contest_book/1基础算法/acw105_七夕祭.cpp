#include<iostream>
#include<algorithm>
#include<cstring>
#include<math.h>
using namespace std;
const int N =1e5+10;
typedef long long ll;
ll r[N],c[N],n,m,t;
int main()
{
    cin>>n>>m>>t;
    for(int i=0;i<t;i++)
    {
        int x,y;
        cin>>x>>y;
        r[x]++,c[y]++;
    }
    ll ans=0;
    bool flagr=false,flagc=false;
    if(t%n==0)
    {
        flagr=true;
        for(int i=1;i<=n;i++)
        {
            r[i]-=t/n;
        }
        for(int i=1;i<=n;i++)
        {
            r[i]=r[i-1]+r[i];
        }
        sort(r+1,r+n+1);
        ll x;
        if(n%2==1)
        x=r[(1+n)/2];
        else
        x=r[n/2];
        for(int i=1;i<=n;i++)
        {
            ans+=abs(r[i]-x);
        }
        
    }
    if(t%m==0)
    {
        flagc=true;
        for(int i=1;i<=m;i++)
        {
            c[i]-=t/m;
        }
        for(int i=1;i<=m;i++)
        {
            c[i]=c[i-1]+c[i];
        }
        sort(c+1,c+m+1);
        ll x;
        if(m%2==1)
        x=c[(1+m)/2];
        else
        x=c[m/2];
        for(int i=1;i<=m;i++)
        {
            ans+=abs(c[i]-x);
        }
    }
    if(flagc&&flagr)
    {
        printf("both %lld\n",ans);
    }
    else if(flagr&&!flagc)
    {
        printf("row %lld\n",ans);
    }
    else if(flagc&&!flagr)
    {
        printf("column %lld\n",ans);
    }
    else
    printf("impossible\n");
    return 0;
}