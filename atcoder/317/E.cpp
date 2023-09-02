#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 3000;
char g[N][N], rg[N][N];
typedef int LL;
int d[N][N];
LL r, c;
LL x1, y1, x2, y2, ans;
void bfs()
{
    memset(d, 0x3f, sizeof d);
    queue<pair<int, int>> q;
    q.push({x1, y1});
    d[x1][y1] = 0;
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        LL dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 1 && x <= r && y >= 1 && y <= c && d[x][y] > 0x3f3f3f3f / 2 && rg[x][y] != '#')
            {
                d[x][y] = d[t.first][t.second] + 1;
                q.push({x, y});
            }
        }
    }
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
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            rg[i][j] = '.';
        }
    }
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (g[i][j] == '>')
            {
                for (int k = j; k <= c && g[i][k] != '<' && g[i][k] != '^' && g[i][k] != '#' && g[i][k] != 'v'; k++)
                {
                    rg[i][k] = '#';
                }
            }
            if (g[i][j] == '<')
            {

                for (int k = j; k >= 1 && g[i][k] != '>' && g[i][k] != '^' && g[i][k] != '#' && g[i][k] != 'v'; k--)
                {
                    rg[i][k] = '#';
                }
            }

            if (g[i][j] == 'v')
            {

                for (int k = i; k <= r && g[k][j] != '<' && g[k][j] != '^' && g[k][j] != '#' && g[k][j] != '>'; k++)
                {
                    rg[k][j] = '#';
                }
            }

            if (g[i][j] == '^')
            {

                for (int k = i; k >= 1 && g[k][j] != '<' && g[k][j] != '>' && g[k][j] != '#' && g[k][j] != 'v'; k--)
                {
                    rg[k][j] = '#';
                }
            }
            if (g[i][j] == '#')
            {
                rg[i][j] = '#';
            }
            if (g[i][j] == 'S')
            {

                x1 = i, y1 = j;
            }
            if (g[i][j] == 'G')
            {
                x2 = i, y2 = j;
            }
        }
    }
    bfs();
    if (d[x2][y2] < 0x3f3f3f3f / 2)
        cout << d[x2][y2] << endl;
    else
        cout << -1 << endl;
    return 0;
}