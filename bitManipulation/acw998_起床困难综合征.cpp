#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 2 * 1e5;
char str[4];
int op[N];
int t[N], n, m, ans;
#define rep(i, x) for (int i = 0; i < (x); i++)
bool cal(int x, int j)
{
    rep(i, n)
    {
        if (op[i] == 0)
            x |= t[i] >> j & 1;
        else if (op[i] == 1)
            x ^= t[i] >> j & 1;
        else
            x &= t[i] >> j & 1;
    }
    return x;
}
int main()
{
    cin >> n >> m;
    rep(i, n)
    {
        scanf("\n%s %d", str, t + i);
        if (*str == 'O')
        {
            op[i] = 0; // OR
        }
        else if (*str == 'X')
            op[i] = 1; // XOR
        else
            op[i] = 2; // AND
    }
    for (int i = 29; ~i; i--)
    {
        if (1 << i <= m)
        {
            bool x = cal(0, i), y = cal(1, i);
            if (x >= y)
                ans |= x << i;
            else
                ans |= y << i,
                    m -= 1 << i;
        }
        else
            ans |= cal(0, i) << i;
    }
    cout << ans << endl;
}
