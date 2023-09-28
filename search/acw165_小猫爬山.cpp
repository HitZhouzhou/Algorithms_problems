#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 20;
int sum[N], cat[N], n, m;
int ans = N;
void dfs(int u, int k)
{
    if (k > ans)
        return;
    if (u == n + 1)
    {
        ans = k;
        return;
    }
    for (int i = 1; i <= k; i++)
    {
        if (sum[i] + cat[u] <= m)
        {
            sum[i] += cat[u];
            dfs(u + 1, k);
            sum[i] -= cat[u];
        }
    }
    sum[k] = cat[u];
    dfs(u + 1, k + 1);
    sum[k] = 0;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> cat[i];
    }
    sort(cat + 1, cat + n + 1);
    reverse(cat + 1, cat + n + 1);
    dfs(0, 1);
    cout << ans << endl;
    return 0;
}