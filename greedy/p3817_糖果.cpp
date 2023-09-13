#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 100;
typedef long long LL;
LL a[N];
int main()
{
    LL n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    LL res = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] + a[i - 1] > x)
        {
            LL sub = a[i] + a[i - 1] - x;
            res += sub;
            if (a[i] >= sub)
                a[i] -= (sub);
            else
            {
                a[i - 1] -= (sub - a[i]);
                a[i] = 0;
            }
        }
    }
    cout << res;
    return 0;
}
