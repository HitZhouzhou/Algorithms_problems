#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 110;
char g[N][N];
int n, m, k, ans;
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> g[i] + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j + k - 1 <= m; j++)
        {
            bool flag = true;
            for (int h = 0; h < k; h++)
            {
                if (g[i][j + h] == '#')
                    flag = false;
            }
            if (flag)
                ans++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j + k - 1 <= n; j++)
        {
            bool flag = true;
            for (int h = 0; h < k; h++)
            {
                if (g[j + h][i] == '#')
                    flag = false;
            }
            if (flag)
                ans++;
        }
    }
    if (k == 1)
    {
        cout << ans / 2 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}