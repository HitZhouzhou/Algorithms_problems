#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> pll;
pll cal(int n, LL m)
{
    if (n == 0)
        return make_pair(0, 0);
    LL len = 1ll << (n - 1), cnt = 1ll << (2 * n - 2);
    pll pos = cal(n - 1, m % cnt);
    LL x = pos.first, y = pos.second;
    LL z = m / cnt;
    if (z == 0)
        return make_pair(y, x);
    if (z == 1)
        return make_pair(x, y + len);
    if (z == 2)
        return make_pair(x + len, y + len);
    return make_pair(2 * len - y - 1, len - x - 1);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        LL n, a, b;
        cin >> n >> a >> b;
        auto s1 = cal(n, a - 1);
        auto s2 = cal(n, b - 1);
        LL x = s1.first - s2.first, y = s1.second - s2.second;
        printf("%.0lf\n", sqrt(x * x + y * y) * 10);
    }

    return 0;
}