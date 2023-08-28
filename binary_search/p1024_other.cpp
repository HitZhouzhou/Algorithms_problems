#include <iostream>
#include <cstdio>
using namespace std;
double a, b, c, d;
int main()
{
    cin >> a >> b >> c >> d;
    int count = 0;
    for (double i = -100; i <= 100; i += 0.0001)
    {
        double x = i;
        if (abs(a * x * x * x + b * x * x + c * x + d - 0) < 0.0001)
        {
            printf("%.2lf ", x);
            count++;
        }
        if (count == 3)
            break;
    }
    return 0;
}