#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
const int mod = 99991;
int H[N], ne[N], idx, snows[N][6], n;
int h(int *a)
{
    int sum = 0, product = 1;
    for (int i = 0; i < 6; i++)
    {
        sum =(sum+a[i])%mod;
        product =(long long)product*a[i]%mod;
    }
    return (sum + product) % mod;
}
bool equal(int *a, int *b)
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            bool eq = 1;
            for (int k = 0; k < 6; k++)
            {
                if (a[(i + k) % 6] != b[(j + k) % 6])
                {
                    eq = 0;
                }
            }
            if (eq)
                return true;
            eq = 1;
            for (int k = 0; k < 6; k++)
            {
                if (a[(i + k) % 6] != b[(6 + j - k) % 6])
                {
                    eq = 0;
                }
            }
            if (eq)
                return true;
        }
    }
    return false;
}
bool insert(int *a)
{
    int head = h(a);
    for (int i = H[head]; i != -1; i = ne[i])
    {
        if (equal(snows[i], a))
        {
            return true;
        }
    }
    memcpy(snows[++idx], a, sizeof(int) * 6);
    ne[idx] = H[head];
    H[head] = idx;
    return false;
}
int main()
{
    memset(H, -1, sizeof H);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a[6];
        for (int j = 0; j < 6; j++)
        {
            scanf("%d", &a[j]);
        }
        if (insert(a))
        {
            puts("Twin snowflakes found.");
            return 0;
        }
    }
    puts("No two snowflakes are alike.");
    return 0;
}