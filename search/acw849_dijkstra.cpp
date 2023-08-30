#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1e6;
int idx, e[N], ne[N], dist[N], w[N], h[N], n, m;
bool state[N];
typedef pair<int, int> PII;
void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}
int dijkstra()
{
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1});
    dist[1] = 0;
    while (q.size())
    {
        auto t = q.top();
        q.pop();
        int x = t.second;
        if (state[x])
            continue;
        state[x] = true;
        for (int i = h[x]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[x] + w[i])
            {
                dist[j] = dist[x] + w[i];
                q.push({dist[j], j});
            }
        }
    }
    if (dist[n] > 0x3f3f3f3f / 2)
        return -1;
    else
        return dist[n];
}
int main()
{
    memset(h, -1, sizeof(h));
    memset(dist, 0x3f, sizeof dist);
    cin >> n >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    int ans = dijkstra();
    cout << ans << endl;
    return 0;
}