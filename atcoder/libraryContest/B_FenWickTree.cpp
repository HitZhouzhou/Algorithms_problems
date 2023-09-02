#include <iostream>
using namespace std;
const int N = 5 * 1e5 + 1000;
typedef long long LL;
LL s[N], a[N];
int n, q;
int lowbit(int x)
{
    return x & (-x);
}
void update(int i, int x)
{
    while (i <= n)
    {
        s[i] += x;
        i += lowbit(i);
    }
}
LL query(int i)
{
    LL sum = 0;
    while (i)
    {
        sum += s[i];
        i -= lowbit(i);
    }
    return sum;
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        LL x;
        scanf("%lld", &x);
        update(i + 1, x);
    }
    while (q--)
    {
        int op, l, r;
        scanf("%d%d%d", &op, &l, &r);
        if (op == 0)
        {
            update(l + 1, r);
        }
        if (op == 1)
        {
            LL ans = query(r) - query(l);
            cout << ans << endl;
        }
    }
    return 0;
}