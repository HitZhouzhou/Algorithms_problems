#include <iostream>
#include <queue>
#include <cstring>
#define MAX 0x3f3f3f3f
#include <algorithm>
using namespace std;
const int N = 1e3;
typedef long long LL;
int p[N][N], dis[N][N], m;
void bfs()
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    dis[0][0] = 0;
    while (!q.empty())
    {
        auto k = q.front();
        q.pop();
        int dist = dis[k.first][k.second];
        int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++)
        {
            int x = k.first + dx[i], y = k.second + dy[i];
            if (x >= 0 && y >= 0 && dist + 1 < p[x][y] && dis[x][y] == -1)
            {
                dis[x][y] = dist + 1;
                if (p[x][y] == MAX)
                {
                    cout << dis[x][y] << endl;
                    return;
                }
                q.push({x, y});
            }
        }
    }
    cout << -1 << endl;
    return;
}
int main()
{
    cin >> m;
    memset(p, MAX, sizeof(p));
    memset(dis, -1, sizeof dis);
    for (int i = 0; i < m; i++)
    {
        int x, y, time;
        cin >> x >> y >> time;
        p[x][y] = min(p[x][y], time);
        int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};
        for (int j = 0; j < 4; j++)
        {

            int rx = x + dx[j], ry = y + dy[j];
            if (rx >= 0 && ry >= 0)
            {
                p[rx][ry] = min(p[rx][ry], time);
            }
        }
    }
    bfs();
    return 0;
}