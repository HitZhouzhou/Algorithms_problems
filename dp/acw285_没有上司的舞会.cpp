#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e4;
int h[N], e[N], ne[N], idx = 1, n, happy[N], f[N][2], st[N];
bool have_father[N];
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int x)
{
    f[x][1] += happy[x];
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        dfs(j);
        f[x][0] += max(f[j][0], f[j][1]);
        f[x][1] += f[j][0];
    }
}
int main()
{
    memset(h, -1, sizeof h);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> happy[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        add(b, a);
        have_father[a] = true;
    }

    int head = 1;
    while (have_father[head])
        head++;
    dfs(head);
    int ans = max(f[head][0], f[head][1]);
    cout << ans << endl;
}