#include <iostream>
#include <cstring>
using namespace std;
const int N = 110;
int f[N][N], g[N][N], ans, r, c;
int dfs(int i, int j)
{
    if (f[i][j])
        return f[i][j];
    f[i][j] = 1;
    int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};
    for (int k = 0; k < 4; k++)
    {
        int x = i + dx[k], y = j + dy[k];
        if (x >= 1 && x <= r && y >= 1 && y <= c && g[x][y] > g[i][j])
        {
            dfs(x, y);
            f[i][j] = max(f[i][j], f[x][y] + 1);
        }
    }
    return f[i][j];
}
int main()
{
    cin >> r >> c;

    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> g[i][j];
        }
    }
    ans = 0;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
            ans = max(ans, dfs(i, j));
    }
    cout << ans << endl;
    return 0;
}