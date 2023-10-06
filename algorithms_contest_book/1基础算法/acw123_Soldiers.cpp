#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
const int N = 1e4 + 10;
int x[N], y[N];
int n;
typedef long long ll;
int main()
{
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    sort(y + 1, y + 1 + n);
    sort(x + 1, x + 1 + n);
    for(int i=1;i<=n;i++)
    {
        x[i]-=i;
    }
    sort(x+1,x+1+n);
    ll midy, midx;
    midx = x[(n + 1) / 2];
    midy = y[(n + 1) / 2];
    for (int i = 1; i <= n; i++)
    {
        ans += abs(y[i] - midy) + abs(x[i] - midx);
    }
    cout << ans << endl;
    return 0;
}