#include <iostream>
#include <cstring>
using namespace std;
const int N = 11;
const int M = 1 << N;
long long f[N][M][N * N];
bool st[M];
long long n, k, num, cnt[M], ok[M];

int main()
{
    cin >> n >> k;
    for (int i = 0; i < (1 << n); i++)
    {
        int tmpi = i, n1 = 0;
        while (tmpi)
        {
            if (tmpi & 1)
                n1++;
            tmpi >>= 1;
        }
        cnt[i] = n1;
        if ((((i >> 1) | (i << 1)) & i) == 0)
        {
            ok[++num] = i;
        }
    }
    memset(f, 0, sizeof(f));
    f[0][0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            long long s1 = ok[j];
            for (int l = 1; l <= num; l++)
            {
                long long s2 = ok[l];
                if (!((s1 | (s1 << 1) | (s1 >> 1)) & s2))
                {
                    for (int h = 0; h <= k; h++)
                    {
                        if (h >= cnt[s1])
                            f[i][s1][h] += f[i - 1][s2][h - cnt[s1]];
                    }
                }
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= num; i++)
    {
        ans += f[n][ok[i]][k];
    }
    cout << ans << endl;
    return 0;
}