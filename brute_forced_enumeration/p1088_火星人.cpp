#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 100;
int a[N], p[N];
bool st[N];
int flag, n, m;
bool flx;
void dfs(int u)
{
    if (flx)
        return;
    if (u == n + 1)
    {
        flag++;
        if (flag == m + 1)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << p[i] << ' ';
            }
            cout << endl;
            flx = true;
            return;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (flag == 0)
            i = a[u];

        if (!st[i])
        {
            p[u] = i;
            st[i] = true;
            dfs(u + 1);
            st[i] = false;
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dfs(1);
    return 0;
}