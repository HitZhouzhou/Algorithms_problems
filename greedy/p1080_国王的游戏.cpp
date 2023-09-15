#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
const int N = 1010;
typedef long long LL;
typedef pair<LL, LL> PLL;
const int LEN = 1010;
int res[LEN], ans[LEN];
void clear(int a[])
{
    memset(a, 0, sizeof(int) * LEN);
}
void read(int a[])
{
    string s;
    cin >> s;
    memset(a, 0, sizeof(int) * LEN);
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        a[n - i - 1] = s[i] - '0';
    }
}
void mul(int a[], int b, int c[])
{
    memset(c, 0, sizeof(int) * LEN);
    for (int i = 0; i < LEN; i++)
    {
        c[i] += a[i] * b;
        if (c[i] > 9)
        {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
}
void print(int a[])
{
    int i = LEN - 10;
    while (a[i] == 0)
    {
        i--;
    }
    for (; i >= 0; i--)
        cout << a[i];
    cout << endl;
}
bool cmp(int a[], int b[])
{
    int i = LEN;
    for (; i >= 0; i++)
    {
        if (a[i] == b[i])
            continue;
        else
            return a[i] < b[i];
    }
}
struct lr
{
    LL l, r;
} a[N];
bool operator<(const lr &a, const lr &b)
{
    return a.l * a.r < b.l * b.r;
}

// a:divided,b:divisor,len:the len of the divisor;
bool greater_eq(int a[], int b[], int last_dg, int len)
{
    if (a[last_dg + len] > 0)
        return true;
    else
    {
        for (int i = len - 1; i >= 0; i--)
        {
            if (a[last_dg + i] > b[i])
                return true;
            if (a[last_dg + i] < b[i])
                return false;
        }
        return true;
    }
}
void div(int a[], int b[], int c[], int d[])
{
    clear(c);
    clear(d);
    int la, lb;
    for (la = LEN - 1;; la--)
    {
        if (a[la - 1] != 0)
            break;
    }
    for (lb = LEN - 1;; lb--)
    {
        if (b[lb - 1] != 0)
            break;
    }
    for (int i = 0; i < LEN; i++)
        d[i] = a[i];

    for (int i = la - lb; i >= 0; i--)
    {
        while (greater_eq(d, b, i, lb))
        {
            for (int j = 0; j < lb; j++)
            {
                d[j + i] -= b[j];
                if (d[j + i] < 0)
                {
                    d[j + i] += 10;
                    d[j + i + 1] -= 1;
                }
            }
            c[i]++;
        }
    }
}
void intTostr(int k, int a[])
{
    int cnt = 0;
    while (k)
    {
        a[cnt++] = k % 10;
        k /= 10;
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i].l >> a[i].r;
    }
    sort(a + 1, a + n + 1);
    memset(ans, -1, sizeof ans);
    res[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int tmp[LEN];
        memset(tmp, 0, sizeof tmp);
        mul(res, a[i].l, tmp);
        int num[LEN];
        intTostr(a[i].r, num);
        int c[LEN], d[LEN];
        div(tmp, num, c, d);
        memcpy(res, tmp, sizeof tmp);
        if (cmp(ans, c))
        {
            memcpy(ans, c, sizeof res);
        }
    }
    print(ans);
    return 0;
}