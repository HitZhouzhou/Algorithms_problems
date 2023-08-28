#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1010;
int p[N][N], n, m;
int vis[N][N];
bool check(int maxp)
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = 1;
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && vis[x][y] == 0 && p[x][y] <= maxp)
            {
                if (x == n - 1)
                    return true;
                vis[x][y] = 1;
                q.push({x, y});
            }
        }
    }
    return false;
}
int SL(int l, int r)
{
    while (l < r)
    {
        memset(vis, 0, sizeof(vis));
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
int main()
{
    cin >> n >> m;
    int minp = 1e9, maxp = -1e9;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> p[i][j];
            minp = min(minp, p[i][j]);
            maxp = max(maxp, p[i][j]);
        }
    }
    int ans = SL(minp, maxp);
    cout << ans << endl;
}