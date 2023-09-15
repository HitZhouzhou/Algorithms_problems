#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 2 * 1e5 + 100;
int a[N], sit[N];
int l, n, k;
bool check(int g)
{
    int size = a[0];
    int y = k;
    for (int i = 1; i < n; i++)
    {
        if (y < 0)
            break;
        if (a[i] - size > g)
        {
            size = size + g;
            y--;
            i--;
        }
        else
        {
            size = a[i];
        }
    }
    return y >= 0;
}
int SL(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
int main()
{
    cin >> l >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << SL(0, 1e7);
    return 0;
}