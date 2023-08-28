#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int q[N];

int SL(int l, int r, int x)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (q[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
}
int SR(int l, int r, int x)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (q[mid] <= x)
        {
            l = mid;
        }
        else
            r = mid - 1;
    }
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%d", &q[i]);
    while (m--)
    {
        int x;
        scanf("%d", &x);
        int l = SL(0, n - 1, x); // 查找左边界 并返回下标l
        if (q[l] != x)
            cout << "-1 -1" << endl; // 如果找不到  返回-1 -1
        else
        {
            cout << l << ' ';                // 如果找到了  输出左下标
            cout << SR(0, n - 1, x) << endl; // 输出右下标
        }
    }
    return 0;
}
