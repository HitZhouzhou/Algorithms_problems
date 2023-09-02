#include <iostream>
using namespace std;
const int N = 1e3 + 500;
char a[N], b[N];
int f[N][N];
int main()
{
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[i][0] = i;
    }
    cin >> m;
    for (int j = 1; j <= m; j++)
    {
        cin >> b[j];
        f[0][j] = j;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            if (a[i] == b[j])
            {
                f[i][j] = min(f[i - 1][j - 1], f[i][j]);
            }
            else
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
        }
    }
    cout << f[n][m] << endl;
    return 0;
}