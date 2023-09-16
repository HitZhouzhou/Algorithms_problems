#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N = 1e5 + 100;
typedef long long LL;
LL a[N], b[N], grade[N], c[N];
int main()
{
    LL n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[a[i]] = i;
        grade[a[i]] = (i - 1) / k + 1;
    }
    long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        int j = c[x]; // j为位置
        ans += grade[x];
        if (j > 1)
        {

            swap(c[a[j]], c[a[j - 1]]);
            swap(grade[a[j]], grade[a[j - 1]]);
            swap(a[j], a[j - 1]);
        }
    }
    cout << ans;
    return 0;
}