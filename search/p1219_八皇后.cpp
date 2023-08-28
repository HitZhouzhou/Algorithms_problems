#include <iostream>
using namespace std;
const int N = 10000;
typedef long long LL;
LL res[N], col[N], dg[N], udg[N], c, n;
void dfs(int u)
{
    if (u > n)
    {
        c++;
        if (c <= 3)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << res[i] << ' ';
            }
            cout << endl;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!col[i] && !dg[u - i + n] && !udg[u + i])
        {
            res[u] = i;
            col[i] = 1, dg[u - i + n] = 1, udg[u + i] = 1;
            dfs(u + 1);
            col[i] = dg[u - i + n] = udg[u + i] = 0;
        }
    }
}
int main()
{
    cin >> n;
    dfs(1);
    cout << c << endl;
}