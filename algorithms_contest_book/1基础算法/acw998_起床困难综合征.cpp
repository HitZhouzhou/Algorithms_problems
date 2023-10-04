#include <iostream>
using namespace std;
typedef pair<string, int> psi;
const int N = 1e5 + 10;
psi door[N];
int n, m;
int cal(int bit, int now)
{
    for (int i = 0; i < n; i++)
    {
        int x = door[i].second >> bit & 1;
        if (door[i].first == "AND")
            now &= x;
        else if (door[i].first == "OR")
            now |= x;
        else
            now ^= x;
    }
    return now;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        char op[5];
        int x;
        scanf("%s%d", op, &x);
        {
            door[i] = make_pair(op, x);
        }
    }
    int val = 0, ans = 0;
    for (int i = 29; i >= 0; i--)
    {
        int res0, res1;
        res0 = cal(i, 0);
        res1 = cal(i, 1);
        if (val + (1 << i) <= m && res0 < res1)
        {
            ans += res1 << i;
            val += 1 << i;
        }
        else
        {
            ans += res0 << i;
        }
    }
    cout << ans << endl;
    return 0;
}