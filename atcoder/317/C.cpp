#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e3;
typedef long long LL;
int n, m;
LL g[N][N];
LL ans, s;
bool state[N];
void dfs(int x, LL sum)
{
    state[x] = true;
    ans = max(ans, sum);
    for (int i = 1; i <= n; i++)
    {
        if (g[x][i] && !state[i])
        {
            dfs(i, sum + g[x][i]);
            state[i] = false;
        }
    }
    state[x] = false;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = c;
        g[b][a] = c;
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(i, 0);
    }
    cout << ans << endl;
}