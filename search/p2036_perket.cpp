#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 20;
typedef int LL;
LL s[N], b[N];
LL ans = 0x3f3f3f3f;
int n;
void dfs(int i, LL x, LL y)
{
    if (i > n)
    {
        if (x == 1 && y == 0)
        {
            return;
        }
        ans = min(ans, abs(x - y));
        return;
    }
    dfs(i + 1, x * s[i], y + b[i]);
    dfs(i + 1, x, y);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &s[i], &b[i]);
    }
    dfs(1, 1, 0);
    cout << ans << endl;
    return 0;
}