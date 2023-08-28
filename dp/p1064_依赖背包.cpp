#include <iostream>
using namespace std;
const int N = 32005;
int f[N];
int v[N][4], p[N][4], c[N];
// v:第一维：组数，第二维：组中的位数
// p:第一维：组数，第二维：组中的位数
// c[i]:第i组的物品总数
int g[N];
int t, n, m;
int nums = 0;
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        int vv, pp, cc; // 价格，重要程度，组数
        cin >> vv >> pp >> cc;
        nums++;
        if (cc == 0)
        {
            t++; // t表示一共有多少组
            c[t] = 1;
            cc = t;
            g[nums] = t;
        }
        else
        {
            cc = g[cc];
            c[cc]++;
        }

        v[cc][c[cc]] = vv;
        p[cc][c[cc]] = pp * vv;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= v[i][1]; j--)
        {
            f[j] = max(f[j], f[j - v[i][1]] + p[i][1]);
            if (c[i] >= 2 && j >= v[i][1] + v[i][2])
            {
                f[j] = max(f[j], f[j - v[i][1] - v[i][2]] +
                                     p[i][1] + p[i][2]);
            }
            if (c[i] >= 3 && j >= v[i][1] + v[i][3])
            {
                f[j] = max(f[j], f[j - v[i][1] - v[i][3]] + p[i][1] + p[i][3]);
            }
            if (c[i] >= 3 && j >= v[i][1] + v[i][2] + v[i][3])
            {
                f[j] = max(f[j], f[j - v[i][1] - v[i][2] - v[i][3]] +
                                     p[i][1] + p[i][2] + p[i][3]);
            }
        }
    }
    std::cout << f[m];
    return 0;
}
