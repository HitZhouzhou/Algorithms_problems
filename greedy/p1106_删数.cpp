#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 300;
int a[N], b[N];
char c[N];
bool st[N];
int len;
int main()
{
    string c;
    int m;
    cin >> c >> m;
    int n = c.length();
    for (int i = 1; i <= c.length(); ++i)
    {
        a[i] = c[i - 1] - '0';
    }
    int t = 1, cnt = 0;
    bool flag = false;
    int rest = n - m;
    while (cnt < rest)
    {
        int minp = t;
        for (int i = t; i <= t + m; ++i)
        {
            if (a[i] < a[minp])
                minp = i;
        }
        m -= (minp - t);
        t = minp + 1;
        if (a[minp])
        {
            flag = true;
        }
        if (flag)
            cout << a[minp];
        cnt++;
    }
    if (!flag)
    {
        cout << 0 << endl;
    }
    return 0;
}