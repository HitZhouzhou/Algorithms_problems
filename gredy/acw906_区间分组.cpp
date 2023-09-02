#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 100;
long long b[N], idx;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        b[idx++] = 2 * l;
        b[idx++] = 2 * r + 1;
    }
    long long ans = 0, cnt = 0;
    sort(b, b + idx);
    for (int i = 0; i < idx; i++)
    {
        if (b[i] % 2 == 0)
        {
            cnt++;
        }
        else
            cnt--;
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}
