#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5 + 100;
int n, m, k, dist[N], back[N];
struct
{
    int a, b, c;
} e[N];
int bellmanFold()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < k; i++)
    {
        memcpy(back, dist, sizeof dist);
        for (int j = 0; j < m; j++)
        {
            int a = e[j].a, b = e[j].b, c = e[j].c;
            dist[b] = min(dist[b], back[a] + c);
        }
    }
    if (dist[n] > 0x3f3f3f3f / 2)
        return -0x3f3f3f3f;
    else
        return dist[n];
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        e[i] = {a, b, c};
    }
    int ans = bellmanFold();
    if (ans == -0x3f3f3f3f)
        cout << "impossible" << endl;
    else
        cout << ans << endl;
}