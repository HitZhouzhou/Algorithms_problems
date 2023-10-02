#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
typedef int LL;
LL a[N], f[N];
LL l, r, n;
LL q[N];
int main()
{
    cin >> n >> l >> r;
    LL ans = -0x3f3f3f3f;
    memset(f, 128, sizeof f);
    f[0] = 0;

    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
    }
    int hh = 0, tt = -1;
    for (int i = l; i <= n; i++)
    {
        if (hh <= tt && q[hh] < i - r)
            hh++;
        while (hh <= tt && f[q[tt]] <= f[i - l])
            tt--;
        q[++tt] = i - l;
        f[i] = max(f[i], f[q[hh]] + a[i]);
        if (i + r > n)
            ans = max(ans, f[i]);
    }
    cout << ans;
    return 0;
}