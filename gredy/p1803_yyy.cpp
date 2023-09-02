#include <iostream>
#include <algorithm>
using namespace std;
const int N = 3 * 1e6 + 100;
int a[N], idx;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        a[idx++] = 2 * l;
        a[idx++] = 2 * r + 1;
    }
    int ans = 0, cnt = 0;
    sort(a, a + idx);
    for (int i = 0; i < idx; i++)
    {
        if (a[i] % 2 == 0)
        {
            cnt++;
        }
        else
            cnt--;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}