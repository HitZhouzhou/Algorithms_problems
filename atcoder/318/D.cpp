#include <iostream>
#include <vector>
using namespace std;
#define rep(i, x) for (int i = 0; i < (x); i++)
const int N = 1e3;
long long d[N][N];
int main()
{
    long long n;
    cin >> n;
    vector<long long> dp(1 << n, 0ll);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            cin >> d[i][j];
    }
    for (int b = 0; b < (1 << n) - 1; b++)
    {
        int l = -1;
        rep(i, n)
        {
            if (!(b >> i & 1))
            {
                l = i;
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (!((b >> i) & 1))
            {
                int nb = b | (1 << i) | (1 << l);
                dp[nb] = max(dp[nb], dp[b] + d[l][i]);
            }
        }
    }
    cout << dp.back();
    return 0;
}