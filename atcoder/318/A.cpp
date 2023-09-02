#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 100;
int n, m, p, ans;
int main()
{
    cin >> n >> m >> p;
    if (m > n)
    {
        cout << 0 << endl;
        return 0;
    }
    ans = 1 + (m - 1) / p + (n - m) / p;
    cout << ans << endl;
    return 0;
}