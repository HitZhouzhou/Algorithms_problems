#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 5 * 1e5 + 1000;
typedef long long LL;
long long a[N], ans, idx;
bool cmp(LL x, LL y)
{
    return x > y;
}
int main()
{
    int n, d, p;
    cin >> n >> d >> p;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n;)
    {
        long long sum = 0;
        for (int j = 0; j < d && i + j < n; j++)
            sum += a[i + j];
        if (sum > p)
        {
            ans += p;
        }
        else
        {
            ans += sum;
        }
        i += d;
    }
    cout << ans;
    return 0;
}