#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e3 + 100;
typedef long long LL;
LL f[N][50000];
LL a[N];
int n, p = 40000;
const int mod = 998244353;
LL ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + 1) % mod; // why
        for (int j = i - 1; j >= 1; j--)
        {
            LL x = a[i] - a[j] + p;
            ans = (ans + f[j][x] + 1) % mod;
            f[i][x] += (f[j][x] + 1) % mod;
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}