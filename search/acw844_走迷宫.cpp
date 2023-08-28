#include <iostream>
#include <queue>
using namespace std;
const int N = 110;
int g[N][N], d[N][N];
int n, m;

void bfs()
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    d[0][0] = 0;
    while (!q.empty())
    {
        auto t = q.front();
        int distance = d[t.first][t.second];
        q.pop();
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && d[x][y] == -1 && g[x][y] == 0)
            {
                d[x][y] = distance + 1;
                q.push({x, y});
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            d[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
        }
    }
    bfs();
    cout << d[n - 1][m - 1];
    return 0;
}