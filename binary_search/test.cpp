#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6;
typedef long long LL;
LL a[N], b[N];
int m, n;
LL SR(LL x)
{
    int l = 0, r = n - 1;
    while (l < r)
    {
        LL mid = 1 + l + r >> 1;
        if (a[mid] <= x)
            l = mid;
        else
            r = mid - 1;
    }
    return r;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    while (m--)
    {
        int q;
        cin >> q;
        cout << SR(q) << endl;
    }
    return 0;
}