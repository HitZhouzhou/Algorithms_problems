#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N =3e6+1000;
const int M =2e5+10;
int trie[N][2],tot,d[M],n;
int h[M],ne[M],e[M],idx,w[M];
void add(int a,int b,int c)
{
    e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}
void dfs(int u,int fa,int sum)
{
    d[u]=sum;
    for(int i=h[u];~i;i=ne[i])
    {
        int j=e[i];
        if(j!=fa)
        {
            dfs(j,u,sum^w[i]);
        }
    }
}
void insert(int x)
{
    int p=0;
    for(int i=31;i>=0;i--)
    {
        int c=(x>>i)&1;
        if(trie[p][c]==0)trie[p][c]=++idx;
        p=trie[p][c];
    }
}
int query(int x)
{
    int p=0,ans=0;
    for(int i=31;i>=0;i--)
    {
        int c=(x>>i)&1;
        if(trie[p][!c])
        {
            ans+=1<<i;
            p=trie[p][!c];
        }
        else
        p=trie[p][c];
    }
    return ans;
}
int main()
{
    memset(h,-1,sizeof h); 
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    dfs(0,-1,0);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        insert(d[i]);
    }
    for(int i=0;i<n;i++)
    {
        ans=max(ans,query(d[i]));
    }
    cout<<ans<<endl;
    return 0;
}