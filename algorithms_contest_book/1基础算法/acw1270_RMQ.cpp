#include<iostream>
#include<math.h>
using namespace std;
const int N =1e5+10;
int a[N],n,f[N][40],m;
void ST_prework()
{
    for(int i=1;i<=n;i++)f[i][0]=a[i];
    int t=log(n)/log(2)+1;
    for(int j=1;j<t;j++)
    {
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
        }
    }
}
int ST_query(int l,int r)
{
    int k=log(r-l+1)/log(2);
    return max(f[l][k],f[r-(1<<k)+1][k]);
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
    ST_prework();
    while(m--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        cout<<ST_query(l,r)<<endl;
    }
    return 0;
}