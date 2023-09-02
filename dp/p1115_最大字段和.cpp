#include <iostream>
using namespace std;
const int N = 1e6;
long long ans = -0x3f3f3f3f, f[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        f[i] = max(x, f[i - 1] + x);
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
    return 0;
}