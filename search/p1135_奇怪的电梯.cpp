#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 500;
typedef long long LL;
int d[N], g[N];
int m, a, b;
void bfs()
{
    queue<int> q;
    q.push(a);
    d[a] = 0;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        int dx[] = {g[t], -g[t]};
        for (int i = 0; i < 2; i++)
        {
            int x = t + dx[i];
            if (x >= 1 && x <= m && d[x] == -1)
            {
                d[x] = d[t] + 1;
                q.push(x);
            }
        }
    }
}
int main()
{
    cin >> m >> a >> b;
    for (int i = 1; i <= m; i++)
    {
        cin >> g[i];
    }
    memset(d, -1, sizeof d);
    bfs();
    cout << d[b];
    return 0;
}