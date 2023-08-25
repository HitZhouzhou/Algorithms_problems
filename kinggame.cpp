#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 1010;
const int LEN = 1004;
int a[LEN], b[LEN];
struct uv
{
    int x, y;
    bool operator<(struct uv &u)
    {
        return max(u.x, x * y) < max(x, u.x * u.y);
    }
};

void clear(int a[])
{
    memset(a, 0, sizeof(int) * LEN);
}
void print(int a[])
{
    int i = LEN - 1;
    for (; i >= 1; i--)
    {
        if (a[i] != 0)
            break;
    }
    for (; i >= 0; i--)
    {
        putchar(a[i] + '0');
    }
    putchar('\n');
}
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
void mul_short(int a[], int b, int c[])
{
    int k = LEN;
    for (;; --k)
    {
        if (a[k] != 0)
            break;
    }
    clear(c);
    for (int i = 0; i <= k; ++i)
    {
        c[i] += a[i] * b;
        if (c[i] >= 10)
        {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
}
bool cmp(uv a, uv b)
{
    return a.operator<(b);
}
int multi[1001][LEN];
int cmpBig(int a[], int b[])
{
    for (int i = LEN - 1; i >= 0; i--)
    {
        if (a[i] > b[i])
            return 1;
        if (a[i] < b[i])
            return -1;
    }
    return 0;
}
int main()
{
    int n;
    cin >> n;
    uv d[N];
    for (int i = 0; i < n + 1; i++)
    {
        cin >> d[i].x >> d[i].y;
    }
    sort(d, d + n + 1, cmp);
    for (int i = 0; i <)
        // for (int i = 0; i < n; i++)
        // {
        //     clear(multi[i]);
        // }
        // multi[0][0] = d[0].x;
        // for (int i = 1; i <= n; i++)
        // {
        //     mul_short(multi[i - 1], d[i - 1].x, multi[i]);
        // }
        // int m[LEN];
        // clear(m);
        // int c[LEN];
        // int res[LEN];
        // for (int i = 0; i < n; i++)
        // {
        //     int dis[LEN];
        //     clear(dis);
        //     int h = d[i].y;
        //     while (h)
        //     {
        //         dis[i] = h % 10;
        //         h /= 10;
        //     }
        //     div(multi[i], dis, c, res);
        //     if (cmpBig(res, m) == 1)
        //         ;
        //     for (int i = 0; i < LEN; i++)
        //         m[i] = res[i];
        // }
        // print(m);
        return 0;
}
