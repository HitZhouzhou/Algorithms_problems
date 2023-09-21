#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1010;
char a[N],b[N];
int f[N][N];
int main()
{
    int n,m;
    cin>>n>>m>>(a+1)>>(b+1);
    for(int i=1;i<=n;i++) 
    {
        for(int j=1;j<=m;j++)
        {
           if(a[i]==b[j]) 
           f[i][j]=f[i-1][j-1]+1;
           else
           f[i][j]=max(f[i-1][j],f[i][j-1]);
        }
    }
    return f[n-1][m-1];
    return 0;
}
