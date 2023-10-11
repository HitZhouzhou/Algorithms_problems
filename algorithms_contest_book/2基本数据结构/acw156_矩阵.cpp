#include<iostream>
#include<unordered_set>
#include<cstring>
using namespace std;
int n,m,a,b;
typedef unsigned long long ULL;
const int N =1010,P=131;
ULL f[N][N],p[N*N];
ULL get(ULL f[],int l,int r)
{
    return f[r]-f[l-1]*p[r-l+1];
}
int main()
{
    cin>>m>>n>>a>>b;
    p[0]=1;
    for(int i=1;i<=m*n;i++)
    {
        p[i]=p[i-1]*131;
    }
    for(int i=1;i<=m;i++)
    {
        char str[N];
        cin>>str+1;
        for(int j=1;j<=n;j++)
        {
            f[i][j]=f[i][j-1]*P+str[j]-'0';
        }
    }
    unordered_set<ULL>hash;
    for(int i=b;i<=n;i++)
    {
        ULL s=0;
        int l=i-b+1,r=i;
        for(int j=1;j<=m;j++)
        {
            s=s*p[b]+get(f[j],l,r);
            if(j>a)s-=get(f[j-a],l,r)*p[a*b];
            if(j>=a)hash.insert(s);
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        ULL s=0;
        for(int i=1;i<=a;i++)
        {
            char str[N];
            cin>>str+1;
            for(int j=1;j<=b;j++)
            {
                s=s*P+str[j]-'0';
            }
        }
        if(hash.find(s)!=hash.end())
        puts("1");
        else 
        puts("0");
    }
    return 0;
}