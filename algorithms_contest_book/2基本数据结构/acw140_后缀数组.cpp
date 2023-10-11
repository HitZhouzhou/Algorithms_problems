#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef unsigned long long ULL;
const int N = 3e6 + 10;
const int base = 131;
ULL f[N], p[N];
char s[N];
int sa[N], n;
ULL get(int l, int r)
{
    return f[r] - f[l - 1] * p[r - l + 1];
}
int get_max_prefix(int a, int b)
{
    int l = 0, r = min(n - a + 1, n - b + 1);
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (get(a, a + mid - 1) == get(b, b + mid - 1))
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}
bool cmp(int a, int b)
{
    int l = get_max_prefix(a, b);
    int av = a + l > n ? INT_MIN : s[a + l];
    int bv = b + l > n ? INT_MIN : s[b + l];
    return av < bv;
}
int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * base;
        f[i] = f[i - 1] * base + s[i] - 'a' + 1;
        sa[i] = i;
    }
    puts("");
    sort(sa + 1, sa + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", sa[i] - 1);
    }
    puts("");
    printf("0 ");
    for (int i = 2; i <= n; i++)
    {
        printf("%d ", get_max_prefix(sa[i - 1], sa[i]));
    }
    puts("");
    return 0;
}