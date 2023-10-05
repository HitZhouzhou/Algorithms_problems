#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 5e5 + 100;
typedef long long ll;
ll a[N], tmp[N], tt[N];
ll k, n, m, t;
ll cal(int l, int mid, int r)
{
    for (int i = mid; i < r; i++)
    {
        tt[i] = a[i];
    }
    sort(tt + mid, tt + r);
    int i = l, j = mid, k = 0;
    while (i < mid && j < r)
    {
        if (tt[i] < tt[j])
            tmp[k++] = tt[i++];
        else
            tmp[k++] = tt[j++];
    }
    while (i != mid)
        tmp[k++] = tt[i++];
    while (j != r)
        tmp[k++] = tt[j++];

    ll ans = 0, tm = m;
    i = 0, j = k - 1;
    while (tm-- && i < j)
    {
        ans += (tmp[i] - tmp[j]) * (tmp[i] - tmp[j]);
        i++, j--;
    }
    return ans;
}
int main()
{
    cin >> k;
    while (k--)
    {
        ll cnt = 0;
        scanf("%lld %lld %lld\n", &n, &m, &t);
        for (int i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        int l = 0, r = 0;
        while (r < n)
        {
            int p = 1;
            while (p)
            {
                if (r + p <= n && cal(l, r, r + p) <= t)
                {
                    r = r + p, p *= 2;
                    if (r >= n)
                        break;
                    for (int i = l; i < r; i++)
                    {
                        tt[i] = tmp[i - l];
                    }
                }
                else
                    p /= 2;
            }
            l = r;
            cnt++;
        }
        printf("%lld\n", cnt);
    }
    return 0;
}