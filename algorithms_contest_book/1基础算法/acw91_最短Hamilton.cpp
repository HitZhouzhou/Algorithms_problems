#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 20;
ll weight[25][25], f[1 << N][N];
int n;
ll hamilton()
{
    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;
    for (int i = 1; i < 1 << N; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >> j & 1)
            {
                for (int k = 0; k < n; k++)
                {
                    if (((i ^ 1 << j) >> k) & 1)
                        f[i][j] = min(f[i][j], f[i ^ (1 << j)][k] + weight[j][k]);
                }
            }
        }
    }
    return f[(1 << n) - 1][n - 1];
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> weight[i][j];
        }
    cout << hamilton() << endl;
    return 0;
}