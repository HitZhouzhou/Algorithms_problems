#include <algorithm>
#include <iostream>
#include<cstring>
#include<limits.h>
using namespace std;
typedef pair<int,int>PII;
const int N =1e5+10;
PII a[N],ans[N];
int l[N],r[N],n,p[N];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+1+n);
    a[0].first=-0x3f3f3f3f,a[n+1].first=0x3f3f3f3f;
    for(int i=1;i<=n;i++)
    {
        l[i]=i-1,r[i]=i+1;
        p[a[i].second]=i;
    }
    for(int i=n;i>1;i--)
    {
        int j=p[i],left=l[j],right=r[j];
        int lv=abs(a[j].first-a[left].first);
        int rv=abs(a[right].first-a[j].first);
        if(lv<=rv)
        {
            ans[i].first=lv,ans[i].second=a[left].second;
        }
        else
        {
            ans[i].first=rv,ans[i].second=a[right].second;
        }
        r[left]=right,l[right]=left;
    }
    for(int i=2;i<=n;i++)
    {
        cout<<ans[i].first<<' '<<ans[i].second<<endl;;
    }
    return 0;
}