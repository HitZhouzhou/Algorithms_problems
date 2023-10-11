#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 60010;
const int M = 120010;
int primes[M], cnt, p[N];
bool st[M];
void mul(vector<ll>&ans,int b)
{
    ll t=0;
    for(int i=0;i<ans.size();i++)
    {
        ans[i]=ans[i]*b+t;
        t=ans[i]/1000000000;
        ans[i]%=1000000000;
    }
    while(t)
    {
        ans.push_back(t%1000000000);
        t/=1000000000;
    }
}
void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}
int get(int n, int p)
{
    int s = 0;
    while (n)
    {
        s += n / p;
        n /= p;
    }
    return s;
}
int main()
{
    int n;
    cin >> n;
    get_primes(2 * n);
    vector<ll> ans;
    for (int i = 0; i < cnt; i++)
    {
        p[primes[i]] = get(2 * n, primes[i]) - 2 * get(n, primes[i]);
    }
    int k = n + 1;
    for (int i = 2; i <= k; i++)
    {
        while (k%i==0)
        {
            p[i]--;
            k /= i;
        }
    }
    ans.push_back(1);
    for(int i=0;i<cnt;i++)
    {
        for(int j=0;j<p[primes[i]];j++)
        {
            mul(ans,primes[i]);
        }
    }
    printf("%lld",ans.back()); 
    for(int i=ans.size()-2;i>=0;i--)
    {
        printf("%09lld",ans[i]);
    }
    cout<<endl;
    return 0;
}