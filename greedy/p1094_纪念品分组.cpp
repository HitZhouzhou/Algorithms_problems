#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int N = 3 * 1e4 + 100;
int p[N];
int w, n;
int main()
{
    cin >> w >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    sort(p, p + n);
    int l = 0, r = n - 1;
    int res = 0;
    while (l <= r)
    {
        if (l == r)
        {
            res++;
            break;
        }
        if (p[l] + p[r] <= w)
        {
            res++;
            l++, r--;
        }
        else
        {
            res++;
            r--;
        }
    }
    cout << res << endl;
    return 0;
}