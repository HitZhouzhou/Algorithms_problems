#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int f[N], v[N], w[N], p[N];
int main()
{
    int a1, a2, b1, b2, n;
    scanf("%d:%d %d:%d %d", &a1, &a2, &b1, &b2, &n);
    int m = (b1 - a1) * 60 + (b2 - a2);
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i] >> p[i];
    for (int i = 1; i <= n; i++)
    {
        if (!p[i])
        {
            for (int j = w[i]; j <= m; j++)
            {
                f[j] = max(f[j], f[j - w[i]] + v[i]);
            }
        }
        else if (p[i] == 1)
        {
            for (int j = m; j >= w[i]; j--)
            {
                f[j] = max(f[j], f[j - w[i]] + v[i]);
            }
        }
        else
        {
            for (int k = 1; k <= p[i]; k *= 2)
            {
                int rv = k * v[i], rw = k * w[i];
                p[i] -= k;
                for (int j = m; j >= rw; j--)
                {
                    f[j] = max(f[j], f[j - w[i]] + v[i]);
                }
            }
            if (p > 0)
            {
                int rv = p[i] * v[i], rw = p[i] * w[i];
                for (int j = m; j >= rw; j--)
                {
                    f[j] = max(f[j], f[j - w[i]] + v[i]);
                }
            }
        }
    }
    cout << f[m] << endl;
    return 0;
}