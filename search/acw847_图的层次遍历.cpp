#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int N = 1e5 + 100;
const int M = 4 * N;

int h[N], e[M], ne[M], idx, d[N], n, m, vis[M];
void bfs()
{
    queue<int> q;
    q.push(1);
    d[1] = 0;
    vis[1] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        int distance = d[x];
        for (int i = h[x]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (!vis[j])
            {
                vis[j] = 1;
                d[j] = distance + 1;
                q.push(j);
            }
        }
    }
}
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    memset(d, 0x3f3f3f3f, sizeof(d));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    bfs();
    if (d[n] < 0x3f3f3f3f)
        cout << d[n];
    else
        cout << -1 << endl;
}