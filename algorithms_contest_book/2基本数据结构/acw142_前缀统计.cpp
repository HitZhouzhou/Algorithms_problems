#include<iostream>
#include<cstring>
using namespace std;
const int N=1e6+10;
int trie[N][26],idx;
int st[N];
char str[N];
void insert(char * str)
{
    int n=strlen(str);
    int p=0;
    for(int k=0;k<n;k++)
    {
        int ch=str[k]-'a';
        if(trie[p][ch]==0)trie[p][ch]=++idx;
        p=trie[p][ch];
    }
    st[p]+=1;
}
int query(char *str)
{
    int n=strlen(str);
    int ans=0;
    int p=0;
    for(int k=0;k<n;k++)
    {
        int ch=str[k]-'a';
        if(trie[p][ch]==0)return ans;
        else
        {
            p=trie[p][ch];
            ans+=st[p];
        }
    }
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        scanf("%s",str);
        insert(str);
    }
    while(m--)
    {
        scanf("%s",str);
        int cnt=query(str);
        cout<<cnt<<endl;
    }
    return 0;
}