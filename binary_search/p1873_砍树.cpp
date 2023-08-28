#include <iostream>
using namespace std;
const int N = 1e6 + 100;
typedef long long LL;
LL a[N];
LL n, m, r;
bool check(LL h)
{
    LL g = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > h)
        {
            g += (a[i] - h);
        }
    }
    return g >= m;
}
int SR()
{
    LL l = 0;
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
    cin >> n >> m;
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