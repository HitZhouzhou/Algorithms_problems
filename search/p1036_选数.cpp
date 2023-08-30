#include <iostream>
using namespace std;
const int N = 30;
typedef long long LL;
LL a[N];
int state[N];
int n, k, rk;
LL ans = 0;
int isPrime(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}
void dfs(int u, int sum, int st)
{
    if (u == k + 1)
    {
        ans += isPrime(sum);
        return;
    }
    for (int i = st; i <= n; i++)
    {
        dfs(u + 1, sum + a[i], i + 1);
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dfs(1, 0, 1);
    cout << ans << endl;
    return 0;
}