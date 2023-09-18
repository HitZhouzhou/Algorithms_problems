#include <iostream>
using namespace std;
const int N = 2 * 1e4 + 100;
int l[N], r[N], f[N][2], n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
    }
    f[1][0] = 2 * r[1] - l[1] - 1;
    f[1][1] = r[1] - 1;
    for (int i = 2; i <= n; i++)
    {
        f[i][0] = r[i] - l[i] + min(f[i - 1][0] + abs(l[i - 1] - r[i]), f[i - 1][1] + abs(r[i - 1] - r[i])) + 1;
        f[i][1] = r[i] - l[i] + min(f[i - 1][0] + abs(l[i - 1] - l[i]), f[i - 1][1] + abs(r[i - 1] - l[i])) + 1;
    }
    int ans = min(f[n][0] + n - l[n], f[n][1] + n - r[n]);
    cout << ans << endl;
    return 0;
}