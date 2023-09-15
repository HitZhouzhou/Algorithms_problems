#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
const int LEN = 1010;
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
int main()
{
    int a[LEN], c[LEN];
    memset(a, 0, sizeof a);
    memset(c, 0, sizeof(c));
    read(a);
    read(c);
    printf("a bigger than c is :%d", cmp(a, c));

    return 0;
}