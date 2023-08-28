#include <iostream>
using namespace std;
const int N = 5 * 1e5 + 100;
long long d[N], L, n, m;
// 检查答案是否在mid的右边
bool check(int mid)
{
    int last = 0, cnt = 0;
    for (int i = 0; i <= n; i++)
    {
        if (d[i] - last < mid)
        {
            cnt++;
        }
        else
        {
            last = d[i];
        }
    }
    return m >= cnt;
}
int SR(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
}
int main()
{
    cin >> L >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    d[n] = L;
    int ans = SR(1, L);
    cout << ans << endl;
    return 0;
}