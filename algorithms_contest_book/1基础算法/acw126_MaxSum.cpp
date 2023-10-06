#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N =110;
int s[N][N],f[N];
int n;
int main()
{
    cin>>n;
    int ans=-0x3f3f3f3f;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>s[i][j];
            s[i][j]+=s[i-1][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            memset(f,0,sizeof f);
            f[1]=s[j][1]-s[i-1][1];
            ans=max(ans,f[1]);
            for(int k=2;k<=n;k++)
            {
                f[k]=max(f[k-1]+s[j][k]-s[i-1][k],s[j][k]-s[i-1][k]);
                ans=max(f[k],ans);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}