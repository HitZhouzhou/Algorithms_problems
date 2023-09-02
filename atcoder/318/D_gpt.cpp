#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 16;
const int INF = 1e9;
typedef long long LL;
long long N;
LL weights[MAXN][MAXN];
LL dp[1 << MAXN][MAXN];

LL solve(int mask, int u)
{
    if (mask == (1 << N) - 1)
        return 0; // All vertices are matched

    if (dp[mask][u] != -1)
        return dp[mask][u];

    LL max_weight = -INF;
    for (int v = u + 1; v < N; ++v)
    {
        if ((mask & (1 << u)) == 0 && (mask & (1 << v)) == 0)
        {
            LL new_mask = mask | (1 << u) | (1 << v);
            LL weight = weights[u][v] + solve(new_mask, u + 1);
            max_weight = max(max_weight, weight);
        }
    }

    max_weight = max(max_weight, solve(mask, u + 1)); // Don't include u in the matching

    return dp[mask][u] = max_weight;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            cin >> weights[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    int result = solve(0, 0);
    cout << result << endl;

    return 0;
}
