#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
double a[N], b[N], sum[N];
int n, len;
int main()
{
    cin >> n >> len;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    double eps = 1e-5;
    double l = -1e6, r = 1e6;
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        for (int i = 1; i <= n; i++)
            b[i] = a[i] - mid;
        for (int i = 1; i <= n; i++)
            sum[i] = (sum[i - 1] + b[i]);
        double ans = -1e10, min_val = 1e10;
        for (int i = len; i <= n; i++)
        {
            min_val = min(min_val, sum[i - len]);
            ans = max(ans, sum[i] - min_val);
        }
        if (ans >= 0)
            l = mid;
        else
            r = mid;
    }
    cout<<int(r*1000)<<endl;
    return 0;
}