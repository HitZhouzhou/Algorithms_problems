#include <iostream>
#include <cstring>
using namespace std;
char a, c;
int f = 1, now = 1, x, b, r, k;
int main()
{
    c = getchar();
    while (c != '\n')
    {
        if (c == '+')
        {
            b += f * x * now;
            f = 1;
            x = 0;
            r = 0;
        }
        if (c == '-')
        {
            b += f * x * now;
            f = -1;
            x = 0;
            r = 0;
        }
        if (c == '=')
        {
            b += f * x * now;
            x = 0;
            r = 0;
            f = 1;
            now = -1;
        }
        if (c >= '0' && c <= '9')
        {
            x = 10 * x + c - '0';
            r = 1;
        }
        if (c >= 'a' && c <= 'z')
        {
            a = c;
            if (r)
                k += now * x * f, x = 0;
            else
                k += now * f;
            r = 0;
        }
        c = getchar();
    }
    b += f * x * now;
    double ans = -(double)b / (double)k;
    if (ans == -0.0)
        ans = 0;
    printf("%c=%0.3lf\n", a, ans);
    return 0;
}