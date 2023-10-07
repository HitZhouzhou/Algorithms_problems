#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 60010, M = 120010;
int primes[M], cnt, q[M];
bool st[M];
void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[i * primes[j]] = true;
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
void mul(vector<ll> &res, int b)
{
    ll t = 0;
    for (int i = 0; i < res.size(); i++)
    {
        res[i] = res[i] * b + t;
        t = res[i] / 1000000000;
        res[i] %= 1000000000;
    }
    while (t)
    {
        res.push_back(t % 1000000000);
        t /= 1000000000;
    }
}

int main()
{
    int n;
    cin >> n;
    get_primes(n * 2);
    for (int i = 0; i < cnt; i++)
    {
        q[primes[i]] = get(2 * n, primes[i]) - get(n, primes[i]) * 2;
    }
    int k = n + 1;
    for (int i = 2; i <= k; i++)
    {
        while (k % i == 0)
        {
            k /= i;
            q[i]--;
        }
    }
    vector<ll> res;
    res.push_back(1);
    for (int i = 2; i <= n * 2; i++)
    {
        while (q[i]--)
        {
            mul(res, i);
        }
    }
    printf("%lld", res.back());
    for (int i = res.size() - 2; i >= 0; i--)
    {
        printf("%09lld", res[i]);
    }
    cout << endl;
    return 0;
}