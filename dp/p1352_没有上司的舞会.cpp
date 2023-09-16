#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 6 * 1e3 + 100;
int e[N], ne[N], idx = 1, h[N], r[N];
int f[N][2], id[N], d[N];
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u)
{
    if (h[u] == -1)
    {
        f[u][0] = 0;
        f[u][1] = r[u];
        return;
    }
    f[u][1] = r[u];
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        dfs(j);
        f[u][1] += f[j][0];
        f[u][0] += max(f[j][1], f[j][0]);
    }
}
int main()
{
    memset(h, -1, sizeof h);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i];
    }
    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> b >> a;
        add(a, b);
        id[b]++;
    }
    int head;
    for (int i = 1; i <= n; i++)
    {
        if (id[i] == 0)
        {
            head = i;
            break;
        }
    }
    dfs(head);
    cout << max(f[head][1], f[head][0]);
    return 0;
}