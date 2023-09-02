#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 3 * 1e5 + 10000;
typedef long long LL;
typedef pair<LL, LL> pll;
pll mp[N];
LL m[N];
int main()
{
    LL n;
    cin >> n;
    if (n == 2)
    {
        LL f1, s1, f2, s2;
        cin >> f1 >> s1 >> f2 >> s2;
        if (f1 == f2)
        {
            if (s1 > s2)
            {
                cout << s1 + s2 / 2 << endl;
                return 0;
            }
            else
            {
                cout << s2 + s1 / 2 << endl;
                return 0;
            }
        }
        else
        {
            cout << s1 + s2 << endl;
            return 0;
        }
    }
    for (LL i = 1; i <= n; i++)
    {
        LL f, s;
        cin >> f >> s;
        m[f] = max(m[f], s);
        LL m1, m2, m3;
        m1 = mp[f].first, m2 = mp[f].second;
        if (m1 > m2)
        {
            m3 = max(m2, s);
            mp[f] = {m1, m3};
        }
        else
        {
            m3 = max(m1, s);
            mp[f] = {m2, m3};
        }
    }
    LL ans = 0, midx = 1, mv;
    for (LL i = 2; i <= n; i++)
    {
        if (m[i] > m[midx])
        {
            midx = i;
        }
    }
    LL sidx = 1;
    for (LL i = 2; i <= n; i++)
    {
        if (m[i] > m[sidx] && (i != midx))
        {
            sidx = i;
        }
    }
    LL ans1;
    if (mp[midx].first > mp[midx].second)
    {
        ans1 = mp[midx].first + mp[midx].second / 2;
    }
    else
        ans1 = mp[midx].second + mp[midx].first / 2;
    LL ans2 = m[midx] + m[sidx];
    cout << max(ans1, ans2);
    return 0;
}
