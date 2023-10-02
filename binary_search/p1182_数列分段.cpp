#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
int a[N], n, m, l, r;
bool check(int x)
{
    int sum = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > x)
            return false;
        if (sum + a[i] <= x)
        {
            sum += a[i];
        }
        else
        {
            cnt++;
            sum = a[i];
        }
    }
    return (cnt+1) <= m;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        r += a[i];
    }
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid ;
        else
            l = mid+1;
    }
    cout << l << endl;
    return 0;
}