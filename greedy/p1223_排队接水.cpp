#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e5;

double sum[N];
struct peo
{
    int t, idx;
    bool operator<(const peo &p)
    {
        return t < p.t;
    }
} p[N];
int main()
{
    int n;
    cin >> n;
    int mmax = 0;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        p[i].t = a;
        p[i].idx = i;
    }
    sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n - 1; i++)
    {
        sum[i] = sum[i - 1] + p[i].t;
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", p[i].idx);
    }
    puts("");
    double ans = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        ans += sum[i];
    }
    printf("%.2lf", ans / n);
    return 0;
}