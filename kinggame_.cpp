#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int oo_min = 0xcfcfcfcf, oo_max = 0x3f3f3f3f;
const int max_size = 4000;

struct p_1
{
    int a, b, c;
} p[1000 + 1];

int n, ans_size;
int ans[max_size];
int sum[max_size];
int temp[max_size];

int cmp_p_1_1(p_1 x, p_1 y)
{
    return x.c < y.c;
}

int get_size(int *a)
{
    for (int i = max_size; i >= 1; i--)
        if (a[i - 1] != 0)
            return i;
    return 0;
}

int cmp_a_1(int *a, int *b)
{
    int a_size = get_size(a), b_size = get_size(b);
    if (a_size < b_size)
        return 1;
    else if (a_size > b_size)
        return 0;
    else
    {
        for (int i = a_size - 1; i >= 0; i--)
            if (a[i] < b[i])
                return 1;
            else if (a[i] > b[i])
                return 0;
        return 0;
    }
}
// mul_short
void calc_1(int *a, int b, int *c)
{
    memset(c, 0, sizeof(c));
    int a_size = get_size(a);
    for (int i = 0; i < a_size; i++)
        c[i] = a[i] * b;
    for (int i = 0; i < a_size; i++)
    {
        if (c[i] >= 10 && i == a_size - 1)
            a_size++;
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
}
// div_short
void calc_2(int *a, int b, int *c)
{
    memset(c, 0, sizeof(c));
    int a_size = get_size(a);
    for (int i = a_size - 1, temp = 0; i >= 0; i--)
    {
        temp = (temp * 10) + a[i];
        c[i] = temp / b;
        temp %= b;
    }
}

int main()
{
    if (~scanf("%d", &n))
    {
        for (int i = 0; i <= n; i++)
        {
            scanf("%d%d", &p[i].a, &p[i].b);
            p[i].c = p[i].a * p[i].b;
        }
        sort(&p[1], &p[n + 1], cmp_p_1_1);
        memset(ans, 0, sizeof(ans));
        memset(sum, 0, sizeof(sum));
        sum[0] = 1;
        for (int i = 0; i <= n; i++)
        {
            if (i > 0)
            {
                memset(temp, 0, sizeof(temp));
                calc_2(sum, p[i].b, temp);
                if (cmp_a_1(ans, temp))
                    memcpy(ans, temp, sizeof(ans));
            }
            memset(temp, 0, sizeof(temp));
            calc_1(sum, p[i].a, temp);
            memcpy(sum, temp, sizeof(sum));
        }
        ans_size = get_size(ans);
        for (int i = ans_size - 1; i >= 0; i--)
            printf("%d", ans[i]);
        printf("\n");
    }
}