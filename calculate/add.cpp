#include <iostream>
#include <cstring>

const int LEN = 1004;
int a[LEN], b[LEN], c[LEN];
using namespace std;
void clear(int a[])
{
    for (int i = 0; i < LEN; i++)
    {
        a[i] = 0;
    }
}
void read(int a[])
{
    static char s[LEN + 1];
    scanf("%s", s);
    int len = strlen(s);
    clear(a);
    for (int i = 0; i < len; i++)
    {
        a[len - i - 1] = s[i] - '0';
    }
}
void add(int a[], int b[], int c[])
{
    clear(c);
    for (int i = 0; i < LEN - 1; i++)
    {
        c[i] += a[i] + b[i];
        if (c[i] >= 10)
        {
            c[i + 1] += 1;
            c[i] = c[i] - 10;
        }
    }
}
void print(int c[])
{
    int i = LEN;
    for (i = LEN; i >= 1; i--)
    {
        if (c[i] != 0)
            break;
    }

    for (; i >= 0; i--)
    {
        putchar(c[i] + '0');
    }
    cout << endl;
}
int main()
{
    read(a);
    read(b);
    add(a, b, c);
    print(c);
    return 0;
}