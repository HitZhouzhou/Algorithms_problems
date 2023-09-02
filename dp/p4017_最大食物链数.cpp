#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e6;
const int mod = 80112002;
long long f[N], h[N], e[N], ne[N], idx, n, m, d[N], backd[N];
void dfs(int x)
{
    if (f[x])
        return;
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        dfs(j);
        f[x] += f[j] % mod;
    }
}
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(b, a);
        d[a]++;     // a的入度++
        backd[b]++; // b的出度++
    }
    memset(f, 0, sizeof f);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (backd[i] == 0)
        {
            f[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 0)
        {
            dfs(i);
            ans += f[i] % mod;
        }
    }
    cout << ans % mod << endl;
    return 0;
}