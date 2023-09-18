#include <iostream>
#include <algorithm>
using namespace std;
#define REP(i) for (int i = 1; i <= 3; i++)
int main()
{
    int n;
    cin >> n;
    if (n < 10 || n > 30)
    {
        puts("0");
        return 0;
    }
    long long cnt = 0;

    REP(a)
    REP(b)
    REP(c)
    REP(d)
    REP(e)
    REP(f)
    REP(g)
    REP(h)
    REP(i)
    REP(j)
    {
        if (a + b + c + d + e + f + g + h + i + j == n)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    REP(a)
    REP(b)
    REP(c)
    REP(d)
    REP(e)
    REP(f)
    REP(g)
    REP(h)
    REP(i)
    REP(j)
    {
        if (a + b + c + d + e + f + g + h + i + j == n)
        {
            printf("%d %d %d %d %d %d %d %d %d %d\n", a, b, c, d, e, f, g, h, i, j);
        }
    }
    return 0;
}