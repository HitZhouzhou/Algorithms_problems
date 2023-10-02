#include <iostream>
using namespace std;
const int N = 6010;
int a[N];
typedef long long ll;
int n;
const int mod = 1e9 + 7;
ll c(ll a, ll b)
{
    if (a < b)
    {
        return 0;
    }
    return a * (a - 1) / 2;
}
int main()
{
    cin >> n;
    ll maxx = 0;
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        maxx = max(maxx, x);
        a[x]++;
    }
    ll ans = 0;
    for (int i = 1; i <= maxx; i++)
    {
        if (a[i] < 2)
        {
            continue;
        }
        ll s1 = 0, s2 = 0;
        s1 = a[i] * (a[i] - 1) / 2;
        for (int j = 1; j <= i / 2; j++)
        {
            if (j == i - j && a[j] >= 2)
            {
                s2 = (a[j] * (a[j] - 1)) / 2;
                ans += s1 * s2;
                ans %= mod;
            }
            if (j != i - j && a[j] >= 1 && a[i - j] >= 1)
            {
                s2 = a[j] * a[i - j];
                ans += s1 * s2;
                ans %= mod;
            }
        }
    }
    cout << ans % mod << endl;
    return 0;
}