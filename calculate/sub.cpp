#include <iostream>
#include <cstring>

const int LEN = 1004;
int a[LEN], b[LEN], c[LEN];

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
    char s[LEN + 1];
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        a[i] = s[len - i - 1] - '0';
    }
}
void sub(int a[], int b[], int c[])
{
    for (int i = 0; i < LEN; i++)
    {
        c[i] = a[i] - b[i];
        if (c[i] < 0)
        {
            c[i] += 10;
            c[i + 1] -= 1;
        }
    }
}
int main()
{
    read(a);
    read(b);

    sub(a, b, c);
    print(c);
    return 0;
}