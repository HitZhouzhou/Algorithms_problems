#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5 + 1000;
int e[N], ne[N], h[N] = {-1}, d[N], idx, n, m;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void topsort()
{
    int q[N], tt = -1, hh = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!d[i])
        {
            q[++tt] = i;
        }
    }
    while (hh <= tt)
    {
        int x = q[hh++];
        for (int i = h[x]; i != -1; i = ne[i])
        {
            int j = e[i];
            d[j]--;
            if (!d[j])
            {
                q[++tt] = j;
            }
        }
    }
    if (tt == n - 1)
    {
        for (int i = 0; i < n; i++)
        {
            cout << q[i] << ' ';
        }
    }
    else
        cout << -1 << endl;
}
int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }

    topsort();
}