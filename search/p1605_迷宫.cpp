#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int n, m, t;
const int N = 20;
typedef pair<int, int> pii;
int g[10][10];
pii s, f;
int st[N][N];
int d[N][N];
int total;
void dfs(int x, int y)
{
    if (x == f.first && y == f.second)
    {
        total++;
        return;
    }
    int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++)
    {
        int nx, ny;
        nx = x + dx[i], ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && g[nx][ny] == 0 && st[nx][ny] == 0)
        {
            st[nx][ny] = 1;
            dfs(nx, ny);
            st[nx][ny] = 0;
        }
    }
}
int main()
{
    cin >> n >> m >> t;
    cin >> s.first >> s.second >> f.first >> f.second;
    for (int i = 0; i < t; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x][y] = 1;
    }
    st[s.first][s.second] = 1;
    dfs(s.first, s.second);
    cout << total << endl;
    return 0;
}