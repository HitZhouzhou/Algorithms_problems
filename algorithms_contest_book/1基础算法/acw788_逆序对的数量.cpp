#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N], tmp[N], n;
typedef long long ll;
ll merge_sort(int l, int r)
{
    if (l >= r)
        return 0;
    int mid = (l + r) >> 1;
    ll cnt = merge_sort(l, mid) + merge_sort(mid + 1, r);
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
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << merge_sort(0, n - 1) << endl;
    ;
    return 0;
}