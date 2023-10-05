#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;
const int N = 300000;
int a[N], b[N], tmp[N], n;
ll merge_sort(int a[], int l, int r)
{
    if (l >= r)
        return 0;
    int mid = (l + r) / 2;
    ll cnt = merge_sort(a, l, mid) + merge_sort(a, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
        {
            tmp[k++] = a[j++];
            cnt += mid - i + 1;
        }
    }
    while (i <= mid)
        tmp[k++] = a[i++];
    while (j <= r)
        tmp[k++] = a[j++];
    for (int i = l, j = 0; i <= r; i++, j++)
        a[i] = tmp[j];
    return cnt;
}
int main()
{
    while (cin >> n)
    {
        ll cnt1 = 0, cnt2 = 0, ans1 = 0, ans2 = 0;
        for (int i = 0; i < n * n; i++)
        {
            int x;
            cin >> x;
            if (x)
                a[cnt1++] = x;
        }
        ans1 = merge_sort(a, 0, cnt1 - 1);
        for (int i = 0; i < n * n; i++)
        {
            int x;
            cin >> x;
            if (x)
                b[cnt2++] = x;
        }
        ans2 = merge_sort(b, 0, cnt2 - 1);
        if (ans1 % 2 != ans2 % 2)
            puts("NIE");
        else
            puts("TAK");
    }
    return 0;
}