#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6;
typedef long long LL;
long long a[N];
long long n, c;
LL SL(LL l, LL r, long long x)
{
    while (l < r)
    {
        LL mid = l + r >> 1;
        if (a[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    if (a[l] == x)
        return l;
    else
        return -1;
}
LL SR(LL l, LL r, LL x)
{
    while (l < r)
    {
        LL mid = l + r + 1 >> 1;
        if (a[mid] <= x)
            l = mid;
        else
            r = mid - 1;
    }
    if (a[r] == x)
        return r;
    else
        return -1;
}
int main()
{
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    LL count = 0;
    for (int i = 0; i < n; i++)
    {
        LL l = SL(i + 1, n - 1, a[i] + c);

        LL r = SR(i + 1, n - 1, a[i] + c);
        if (l >= 0)
            count += (r - l + 1);
    }
    cout << count << endl;
    return 0;
}