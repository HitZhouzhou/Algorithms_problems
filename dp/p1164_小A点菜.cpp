#include <iostream>
using namespace std;
const int N = 1e4 + 10;
int m, n, f[N][N], a[N];
int main()
{
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
            if (j >= a[i])
            {
                f[i][j] += f[i - 1][j - a[i]];
            }
        }
    }
    cout << f[n][m];
    return 0;
}