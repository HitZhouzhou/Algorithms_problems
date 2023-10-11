#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;
const int N =1e6+10;
char s[N];
typedef unsigned long long ULL;
ULL f[N],p[N];
const int P=131;
ULL get(int l,int r)
{
    return f[r]-f[l-1]*p[r-l+1];
}
int main()
{
    scanf("%s",s+1);
    int t;
    cin>>t;
    int n=strlen(s+1);
    p[0]=1;
    for(int i=1;i<=n;i++)
    {
        f[i]=(f[i-1]*131+s[i]-'a'+1);
        p[i]=p[i-1]*131;
    }
    while(t--)
    {
        int l1,r1,l2,r2;
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        if(get(l1,r1)==get(l2,r2))
        {
            puts("Yes");
        }
        else
        puts("No");
    }

}