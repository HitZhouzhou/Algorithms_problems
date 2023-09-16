#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <assert.h>
using namespace std;
const int N = 2e5 + 1000;
const int M = 2 * 1e5 + 1000;
typedef long long LL;
LL e[M], idx, ne[M], h[M], w[M];
LL ans[N];
LL n;
int bfs(LL u)
{
    LL f[N];
    bool st[N];
    for (int i = 1; i <= n; i++)
    {
        st[i] = false;
    }
    memset(f, 0, sizeof f);
    f[u] = 0;
    st[u] = true;
    queue<LL> q;
    q.push(u);
    LL tmp = 0;
    int pos = u;
    while (!q.empty())
    {
        LL t = q.front();
        q.pop();
        for (int i = h[t]; ~i; i = ne[i])
        {
            LL j = e[i];
            if (!st[j])
            {
                q.push(j);
                f[j] = f[t] + w[i];
                st[j] = true;
                if (f[j] > tmp)
                {
                    tmp = f[j];
                    pos = j;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
            cout << "oops" << endl;
        ans[i] = max(ans[i], f[i]);
    }
    return pos;
}
void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}
int main()
{
    while (~scanf("%lld", &n) && n)
    {
        memset(e, 0, sizeof e);
        memset(ne, 0, sizeof ne);
        memset(h, -1, sizeof h);
        memset(w, 0, sizeof w);
        memset(ans, 0, sizeof ans);
        idx = 0;
        for (int i = 2; i <= n; i++)
        {
            int a, c;
            cin >> a >> c;
            add(a, i, c);
            add(i, a, c);
        }
        int npos = bfs(1);
        int nnpos = bfs(npos);
        bfs(nnpos);
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] << endl;
        }
    }
    return 0;
}