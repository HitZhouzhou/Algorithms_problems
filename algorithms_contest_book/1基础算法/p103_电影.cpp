#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2e5 + 50;
typedef int ll;
int a[N], b[N], c[N], d[3 * N], e[3 * N];
int ans[3 * N];
int n, m, cnt, num;
int query(int x)
{
    return lower_bound(e + 1, e + 1 + num, x) - e;
}
int main()
{
    cin >> n ;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        d[++cnt] = a[i];
    }
    cin>>m;
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        d[++cnt] = b[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> c[i];
        d[++cnt] = c[i];
    }
    sort(d + 1, d + 1 + cnt);
    for (int i = 1; i <= cnt; i++)
    {
        if (i == 1 || d[i] != d[i - 1])
        {
            e[++num] = d[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans[query(a[i])]++;
    }
    int movie = 1, ans0 = 0, ans1 = 0;
    for (int i = 1; i <= m; i++)
    {
        int ansx = ans[query(b[i])], ansy = ans[query(c[i])];
        if (ansx > ans0 || (ansx == ans0 && ansy > ans1))
        {
            movie = i;
            ans0 = ansx;
            ans1 = ansy;
        }
    }
    cout << movie << endl;
}