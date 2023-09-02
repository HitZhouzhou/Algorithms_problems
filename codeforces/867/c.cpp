#include <iostream>
using namespace std;
typedef long long LL;
const int N = 1e9 + 10;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        LL x = 0;
        LL ans = 0;
        scanf("%lld", &x);
        ans = 26 + x - 4 + (5 + x) * (x - 4);
        cout << ans << endl;
    }
    return 0;
}