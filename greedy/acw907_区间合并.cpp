#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e7;
int n;
struct Range
{
    int l, r;
    bool operator<(Range &w)
    {
        return l < w.l;
    }
} range[N];
int main()
{
    int s, t, cnt;
    cin >> s >> t;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> range[i].l >> range[i].r;
    }
    sort(range, range + n);
    int res = 0;
    bool success = false;
    for (int i = 0; i < n; i++)
    {
        int j = i, r = -2e9;
        while (j < n && range[j].l <= s)
        {
            r = max(r, range[j].r);
            j++;
        }
        if (r < s)
        {
            success = false;
            res = -1;
            break;
        }
        res++;
        if (r >= t)
        {
            success = true;
            break;
        }
        s = r;
        i = j - 1;
    }
    if (success)
        cout << res << endl;
    else
        cout << -1 << endl;
    return 0;
}
