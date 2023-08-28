#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6;
typedef long long LL;
LL a[N], b[N];
int m, n;
LL SR(LL x)
{
    int l = 0, r = m - 1;
    while (l < r)
    {
        LL mid = 1 + l + r >> 1;
        if (a[mid] <= x)
            l = mid;
        else
            r = mid - 1;
    }
    return r;
}
int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(a, a + m);
    sort(b, b + n);
    LL ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (b[i] >= a[m - 1])
        {
            ans += abs(a[m - 1] - b[i]);
            continue;
        }
        if (b[i] <= a[0])
        {
            ans += (a[0] - b[i]);
            continue;
        }
        int tmp = SR(b[i]);
        LL tmp2 = min(abs(a[tmp] - b[i]), abs(a[tmp + 1] - b[i]));
        // tmp2 = min(abs(a[tmp - 1] - b[i]), tmp2);
        ans += tmp2;
    }
    cout << ans;
    return 0;
}