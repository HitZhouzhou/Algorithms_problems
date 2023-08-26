#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;
const int N = 1e3 + 10;
int f[N];
int b[N], g[N][N], v[N], w[N], t;
int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> w[i] >> v[i] >> x;
        t = max(t, x);
        b[x]++;
        g[x][b[x]] = i;
    }
    for (int i = 1; i <= t; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            for (int k = 1; k <= b[i]; k++)
            {
                if (j >= w[g[i][k]])
                    f[j] = max(f[j], f[j - w[g[i][k]]] + v[g[i][k]]);
            }
        }
    }
    cout << f[m];
    return 0;
}