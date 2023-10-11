#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N =4e6;
const int M =1e5+10;
int trie[N][2],idx;
int a[M],n;
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
    int p=0;
    int ans=0;
    for(int i=31;i>=0;i--)
    {
        int c=(x>>i)&1;
        if(trie[p][!c])
        {
            ans+=1<<i;
            p=trie[p][!c];
        }
        else
        {
            p=trie[p][c];
        }
    }
    return ans;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        insert(a[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,query(a[i]));
    }
    cout<<ans<<endl;
    return 0;
}