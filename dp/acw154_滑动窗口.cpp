#include <iostream>
#include <string>
using namespace std;
const int N = 1000100;
int a[N], q[N], k, n;
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {
        if (hh <= tt && q[hh] < i - k + 1)
            hh++;
        while (hh <= tt && a[q[tt]] >= a[i])
            tt--;
        q[++tt] = i;
        if (i >= k - 1)
            printf("%d ", a[q[hh]]);
    }
    puts("");
    hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {
        if (hh <= tt && q[hh] < i - k + 1)
            hh++;
        while (hh <= tt && a[q[tt]] <= a[i])
            tt--;
        q[++tt] = i;
        if (i >= k - 1)
            printf("%d ", a[q[hh]]);
    }
    return 0;
}