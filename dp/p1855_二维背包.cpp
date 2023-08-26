#include <iostream>

using namespace std;

const int N = 1e3;

int f[N][N];
int n, m, t, mon[N], tim[N];
int main()
{
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> mon[i] >> tim[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= mon[i]; j--)
        {
            for (int k = t; k >= tim[i]; k--)
            {
                f[j][k] = max(f[j][k], f[j - mon[i]][k - tim[i]] + 1);
            }
        }
    }
    cout << f[m][t];
    return 0;
}