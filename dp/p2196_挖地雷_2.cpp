#include <iostream>
using namespace std;
const int N = 30;
int g[N][N], ans, pre[N], f[N], a[N], t;
void print(int x)
{
    if (pre[x] == 0)
    {
        printf("%d", x);
        return;
    }
    print(pre[x]);
    printf(" %d", x);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (g[j][i] && (f[i] < f[j]))
            {
                f[i] = f[j];
                pre[i] = j;
            }
        }
        f[i] += a[i];
        if (f[i] > ans)
        {
            t = i;
            ans = f[i];
        }
    }

    print(t);
    cout << endl;
    cout << ans << endl;
}