#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int h[N], f[N], n;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        int l = 0, r = len;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (f[mid] < h[i])
                l = mid;
            else
                r = mid - 1;
        }
        f[l + 1] = h[i];
        len = max(len, r + 1);
    }
    cout << len;
    return 0;
}