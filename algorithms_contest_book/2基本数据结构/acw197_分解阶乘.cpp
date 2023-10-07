#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
const int N =1e6+100;
int p[N],primes[N],cnt;
bool st[N];
void get_primes(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!st[i])primes[cnt++]=i;
        for(int j=0;primes[j]<=n/i;j++)
        {
            st[primes[j]*i]=true;
            if(i%primes[j]==0)
            break;
        }
    }
}
int get(int n,int p)
{
    int s=0;
    while(n)
    {
        s+=n/p;
        n/=p;
    }
    return s;
}
int main()
{
    cin>>n;
    get_primes(n);
    for(int i=0;i<cnt;i++)
    {
        p[primes[i]]=get(n,primes[i]);
    }
    for(int i=2;i<=n;i++)
    {
        if(p[i])
        printf("%d %d\n",i,p[i]);
    }
    return 0;
}