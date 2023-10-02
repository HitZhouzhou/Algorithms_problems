#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
ll n, len;
string s;
ll ans = 0x3f3f3f3f, t;
void dfs(ll c, ll x, ll sum) // c:段数,x:位置,sum:和
{
    if (sum == n && x == len)
    {
        ans = min(ans, c - 1);
        return;
    }
    for (int k = 1; k + x <= len; k++)
    {
        t = 0;
        for (int i = x; i < x + k; i++)
        {
            t = t * 10 + (s[i] - '0');
        }
        if (t + sum <= n)
        {
            dfs(c + 1, x + k, sum + t);
        }
        else
            return;
    }
}

int main()
{
    cin >> s;
    cin >> n;
    len = s.length();
    dfs(0, 0, 0);
    if (ans == 0x3f3f3f3f)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}