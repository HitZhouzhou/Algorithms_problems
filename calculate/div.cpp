#include <iostream>
#include <cstring>

using namespace std;

const int LEN = 1004;

int a[LEN], b[LEN], c[LEN], d[LEN];

void clear(int a[])
{
    memset(a, 0, sizeof(int) * LEN);
}
void print(int a[])
{
    int i = LEN;
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
void read(int a[])
{
    clear(a);
    char s[LEN + 1];
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        a[i] = s[len - i - 1] - '0';
    }
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
int main()
{
    read(a);
    read(b);
    div(a, b, c, d);
    print(c);
    putchar('\n');
    print(d);
    return 0;
}