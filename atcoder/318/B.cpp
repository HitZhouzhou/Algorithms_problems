#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e2 + 100;
char g[N][N];
int main()
{
    int n, a, b, c, d;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c >> d;
        for (int j = a; j < b; j++)
        {
            for (int k = c; k < d; k++)
            {
                g[j][k] = '#';
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (g[i][j] == '#')
            {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}