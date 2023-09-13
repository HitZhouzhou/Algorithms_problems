#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N = 1e6;
typedef long long LL;
typedef pair<LL, LL> PII;
LL n, m;
PII a[N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + m + 1);
    long long sum = 0;
    for (int i = 1; i <= m; i++)
    {
        if (n >= a[i].second)
        {
            sum += a[i].first * a[i].second;
            n -= a[i].second;
        }
        else
        {
            sum += a[i].first * n;
            n = 0;
            break;
        }
    }
    cout << sum;
    return 0;
}