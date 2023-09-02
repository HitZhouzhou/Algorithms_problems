#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e4;
int a[N], f[N][N];
int mod = 1e6 + 7;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            f[i][j] = f[i - 1][j];
            for (int k = 1; k <= min(j, a[i]); k++)
            {
                f[i][j] = (f[i - 1][j - k] + f[i][j]) % mod;
            }
        }
    }
    cout << f[n][m] % mod;
    return 0;
}