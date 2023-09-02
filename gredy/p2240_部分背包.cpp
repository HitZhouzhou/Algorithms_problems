#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e4;
struct oj
{
    double w, v;
    bool operator<(const oj &x)
    {
        return v / w > x.v / x.w;
    }
} h[N];
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i].w >> h[i].v;
    }
    sort(h + 1, h + 1 + n);
    double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (m >= h[i].w)
        {
            ans += h[i].v;
            m -= h[i].w;
        }
        else
        {
            ans += h[i].v / (h[i].w) * m;
            m -= m;
            break;
        }
    }
    printf("%.2lf", ans);
    return 0;
}
