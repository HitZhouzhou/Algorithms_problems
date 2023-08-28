#include <iostream>
using namespace std;
const int N = 1e5 + 100;
typedef long long LL;
LL a[N];
LL n, k, l, r;
bool check(LL mx)
{
    LL rk = 0;
    for (int i = 0; i < n; i++)
    {
        rk += a[i] / mx;
    }
    return rk >= k;
}
LL SR()
{
    while (l < r)
    {
        LL mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    return r;
}
int main()
{
    cin >> n >> k;
    r = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        r = max(r, a[i]);
    }
    LL ans = SR();
    cout << ans << endl;
    return 0;
}