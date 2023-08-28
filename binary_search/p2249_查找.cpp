#include <iostream>
using namespace std;
const int N = 1e6 + 100;
long long a[N];
int n, m;
int SL(int q)
{
    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (a[mid] >= q)
            r = mid;
        else
            l = mid + 1;
    }
    if (a[l] == q)
        return l;
    else
        return -1;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (m--)
    {
        int q;
        cin >> q;
        cout << SL(q) << ' ';
    }
    return 0;
}
