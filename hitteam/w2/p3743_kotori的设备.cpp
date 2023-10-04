#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 2e5 + 100;
int n;
double p, a[N], b[N];
bool check(double t)
{
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        double tmp = a[i] * t - b[i];
        if (tmp > 0)
            sum += tmp;
    }
    return sum <= p * t;
}
int main()
{
    cin >> n >> p;
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        sum += a[i];
    }
    if (sum <= p)
    {
        cout << -1 << endl;
        return 0;
    }
    double l = 0, r = 1e10;
    while (r - l >= 1e-5)
    {
        double mid = (r + l) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << endl;
    return 0;
}