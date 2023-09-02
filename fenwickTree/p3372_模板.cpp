#include <iostream>
using namespace std;
const int N = 1e5 + 1000;
typedef long long LL;
LL s[N];
int lowbit(int i)
{
    return i & -i;
}
void add(LL x, LL y, LL num)
{
    for (LL i = x; i <= y; i += lowbit(i))
    {
        s[i] += num;
    }
}
LL query(LL x, LL y)
{
    LL ans;
    for (LL i = x; i; i -= lowbit(i))
    {
        ans += s[i];
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        add(i + 1, i + 1, a);
    }
    while (m--)
    {
        int op, x, y;
        if (op == 1)
        {
            int k;
            cin >> k;
            add(x + 1, y, k);
        }
        else
        {
            cout << query(x, y) << endl;
        }
    }

    return 0;
}