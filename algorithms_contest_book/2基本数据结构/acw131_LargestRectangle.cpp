#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5 + 20;
struct Rectangle
{
    ll h, w;
} r[N];
int a[N];
int n, tt;
int main()
{
    while (cin >> n, n)
    {
        ll ans = 0;
        a[n + 1] = tt = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n+1; i++)
        {
            if (a[i] > r[tt].h)
            {
                r[++tt].h = a[i];
                r[tt].w = 1;
            }
            else
            {
                int width = 0;
                while (r[tt].h > a[i])
                {
                    width += r[tt].w;
                    ans = max(ans, (ll)width * r[tt--].h);
                }
                r[++tt].h = a[i], r[tt].w = width + 1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}