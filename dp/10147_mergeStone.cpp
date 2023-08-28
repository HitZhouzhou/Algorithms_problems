#include <iostream>
using namespace std;
const int N = 500;
int s[N], f[N][N], g[N][N], n;
int a[N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        a[i] = s[i];
        s[i] += s[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        s[i + n] = a[i] + s[n + i - 1];
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= 2 * n; i++)
        {
            int l = i, r = i + len - 1;
            f[l][r] = 0x3f3f3f3f;
            g[l][r] = 0;
            for (int k = l; k < r; k++)
            {
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
                g[l][r] = max(g[l][r], g[l][k] + g[k + 1][r] + s[r] - s[l - 1]);
            }
        }
    }
    int ansmin = 0x3f3f3f3f;
    int ansmax = 0;
    for (int i = 1; i < n; i++)
    {
        ansmin = min(ansmin, f[i][i + n - 1]);
        ansmax = max(ansmax, g[i][i + n - 1]);
    }
    cout << ansmin << endl
         << ansmax << endl;
    return 0;
}