#include <iostream>
#include <algorithm>
using namespace std;
const int N = 500;
int a[N];
int n;
typedef long long LL;
LL res;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int l = 1, r = n;
    int flag = 1, now = 0;
    if (n == 1)
    {
        cout << a[1] * a[1] << endl;
        return 0;
    }
    while (l <= r)
    {
        if (flag)
        {
            res += (a[now] - a[r]) * (a[now] - a[r]);
            now = r;
            flag = 0;
            r--;
        }
        else
        {
            res += (a[now] - a[l]) * (a[now] - a[l]);
            now = l;
            flag = 1;
            l++;
        }
    }
    cout << res << endl;
    return 0;
}