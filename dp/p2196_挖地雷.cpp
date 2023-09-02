#include <iostream>
#include <cstring>
using namespace std;
const int N = 30;
int g[N][N], n, a[N], p[N], mmax, cnt, ans[N], st[N];
bool check(int x)
{
    for (int i = x + 1; i <= n; i++)
    {
        if (g[x][i] && !st[i])
            return true;
    }
    return false;
}
void dfs(int nd, int stp, int sum)
{
    if (sum > mmax)
    {
        mmax = sum;
        memcpy(ans, p, sizeof p);
        cnt = stp;
    }
    for (int i = nd + 1; i <= n; i++)
    {
        if (g[nd][i] && !st[i])
        {
            st[i] = 1;
            p[stp + 1] = i;
            dfs(i, stp + 1, sum + a[i]);
            st[i] = 0;
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int x;
            cin >> x;
            g[i][j] = x;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        p[1] = i;
        st[i] = true;
        dfs(i, 1, a[i]);
        st[i] = 0;
    }
    for (int i = 1; i <= cnt; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
    cout << mmax;
}
