#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;
long double a, b, c, d;
long double f(long double x)
{
    return a * x * x * x + b * x * x + c * x + d;
}
long double bsearch(long double l, long double r)
{
    while (r - l >= 0.001)
    {
        long double mid = (l + r) / 2;
        if (f(mid) * f(r) < 0) // Check f(mid) and f(r) for opposite signs
        {
            l = mid;
        }
        else
            r = mid;
    }
    return l;
}

int main()
{
    scanf("%Lf%Lf%Lf%Lf", &a, &b, &c, &d);
    int count = 0;
    for (long double i = -100; i < 100; i++)
    {
        long double l = i, r = i + 1;
        if (!f(l))
        {
            printf("%.2Lf ", l);
            count++;
        }
        if (f(l) * f(r) < 0)
        {
            long double ans = bsearch(l, r);
            printf("%.2Lf ", ans);
            count++;
        }
        if (count == 3)
            break;
    }
    return 0;
}