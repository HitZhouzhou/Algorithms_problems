#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 60;
char g[N][N];
int n, m;
int w[N], r[N], b[N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> (g[i] + 1);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {

            if (g[i][j] != 'W')
                w[i]++;
            if (g[i][j] != 'B')
                b[i]++;
            if (g[i][j] != 'R')
                r[i]++;
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 2; i <= n - 1; i++)
    {
        for (int j = i; j <= n - 1; j++)
        {
            int sum = 0;
            for (int k = 1; k < i; k++)
            {
                sum += w[k];
            }
            for (int k = i; k <= j; k++)
            {
                sum += b[k];
            }
            for (int k = j + 1; k <= n; k++)
            {
                sum += r[k];
            }
            ans = min(ans, sum);
        }
    }
    cout << ans << endl;
    return 0;
}