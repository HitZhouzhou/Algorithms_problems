#include<iostream>
#include<algorithm>
#include<cstring>
#include<string.h>
using namespace std;
const int N=1e6+10;
char s[N];
typedef unsigned long long ULL;
ULL f[N],p[N],rf[N];
int n;
ULL get(int l,int r)
{
    return f[r]-f[l-1]*p[r-l+1];
}
ULL get_rev(int l,int r)
{
    return rf[l]-rf[r+1]*p[r-l+1];
}
int main()
{
    int cnt=0;
    while(cin>>(s+1),*(s+1)!='E')
    {
        cnt++;
        p[0]=1;
        n=strlen(s+1); 
        for(int i=1;i<=n;i++)
        {
            f[i]=f[i-1]*131+s[i]-'a'+1;
            p[i]=p[i-1]*131;
        }
        for(int i=n;i>=1;i--)
        {
            rf[i]=rf[i+1]*131+s[i]-'a'+1;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int p,q;
            int l=0,r=min(i-1,n-i);  
            while(l<r)
            {
                int mid=(l+r+1)>>1;
                if(get(i-mid,i)==get_rev(i,i+mid))
                l=mid;
                else
                r=mid-1;
            }
            p=2*l+1;
            l=0,r=min(i-1,n+1-i);
            while(l<r)
            {
                int mid=(l+r+1)>>1;
                if(get(i-mid,i-1)==get_rev(i,i+mid-1))
                l=mid;
                else
                r=mid-1;
            }
            q=2*l;
            ans=max(max(p,q),ans);
        }
        printf("Case %d: %d\n",cnt,ans);
    }
    return 0;
}