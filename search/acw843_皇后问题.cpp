#include <iostream>
#include <queue>
using namespace std;
const int N = 10;
char g[N][N];
int dg[N], udg[N], col[N];
int n;
void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i++)
        {
            puts(g[i]);
        }
        puts("");
        return;
    }
    int x = u;
    for (int y = 0; y < n; y++)
    {
        if (dg[y - x + n] == 0 && !col[y] && !udg[x + y])
        {
            g[x][y] = 'Q';
            dg[y - x + n] = 1, col[y] = 1, udg[x + y] = 1;
            dfs(x + 1);
            dg[y - x + n] = 0, col[y] = 0, udg[x + y] = 0;
            g[x][y] = '.';
        }
        ls
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            g[i][j] = '.';
        }
    }
    dfs(0);
    return 0;
}