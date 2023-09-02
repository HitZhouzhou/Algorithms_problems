#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e4;
int a[N][N], f[N][N];
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        f[n][i] = a[n][i];
    }
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            f[i][j] = max(f[i + 1][j] + a[i][j], f[i + 1][j + 1] + a[i][j]);
        }
    }
    cout << f[1][1];
    return 0;
}