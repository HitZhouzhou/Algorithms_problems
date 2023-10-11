#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<limits.h>
using namespace std;
const int N =3e5+10;
typedef long long ll;
ll s[N],q[N];
int n,m;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        s[i]+=s[i-1];
    }
    ll ans=INT_MIN; 
    int h=0,t=0;
    for(int i=1;i<=n;i++) 
    {
        if(i-q[h]>m)h++;
        ans=max(ans,s[i]-s[q[h]]);
        while(h<=t&&s[i]<=s[q[t]])t--;
        q[++t]=i;
    }
    cout<<ans<<endl;
    return 0;
}