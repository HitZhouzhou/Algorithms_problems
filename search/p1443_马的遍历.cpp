#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 500;
int g[N][N], d[N][N];
int m, n, x, y;
void bfs()
{
    queue<pair<int, int>> q;
    q.push({x, y});
    d[x][y] = 0;
    int dx[] = {-1, -1, 1, 1, -2, -2, 2, 2}, dy[] = {-2, 2, -2, 2, -1, 1, -1, 1};
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        int distance = d[t.first][t.second];
        for (int i = 0; i < 8; i++)
        {
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            if (x >= 1 && x <= n && y >= 1 && y <= m && d[x][y] == -1)
            {
                d[x][y] = distance + 1;
                q.push({x, y});
            }
        }
    }
}
int main()
{
    cin >> n >> m >> x >> y;
    memset(d, -1, sizeof(d));
    bfs();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << d[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}