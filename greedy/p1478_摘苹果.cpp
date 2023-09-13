#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N = 1e4;
int n, s, a, b, c[N];
int main()
{
    cin >> n >> s;
    cin >> a >> b;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (a + b >= x)
        {
            c[cnt++] = y;
        }
    }
    sort(c, c + cnt);

    int res = 0;
    for (int i = 0; s >= 0 && i < cnt; i++)
    {
        if (s >= c[i])
        {
            res++;
            s -= c[i];
        }
        if (s < c[i])
            break;
    }
    cout << res;
    return 0;
}