#include <iostream>
using namespace std;

const int N = 100010;
long long a[N], q[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int len = 0;
    q[0] = -1e9 - 1000;
    for (int i = 0; i < n; i++)
    {
        int l = 0, r = len + 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (q[mid] >= a[i])
                r = mid;
            else
                l = mid + 1;
        }
        len = max(len, l);
        q[l] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << q[i] << ' ';
    }
    cout << len << endl;
    return 0;
}