#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5;
typedef long long LL;
LL v[N], cost[N], f[N];
LL n, s;
int main()
{
    cin >> n;
    int x, y, z;
    for (LL i = 1; i <= n; i++)
    {
        cin >> x >> y >> z;
        s += z;
        if (x > y)
        {

            v[i] = z;
            cost[i] = 0;
        }
        else
        {
            v[i] = z;
            cost[i] = (y + x) / 2 + 1 - x;
        }
    }
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    for (LL i = 1; i <= n; i++)
    {
        for (LL j = s; j >= v[i]; j--)
        {
            f[j] = min(f[j - v[i]] + cost[i], f[j]);
        }
    }
    LL ans = 1e18;
    for (LL i = s / 2 + 1; i <= s; i++)
    {
        ans = min(ans, f[i]);
    }
    cout << ans << endl;
    return 0;
}