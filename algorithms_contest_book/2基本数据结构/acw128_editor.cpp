#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e6 + 10;
int stkl[N], stkr[N], sum[N], f[N];
int tl, tr;
void push_l(int x)
{
    stkl[++tl] = x;
    sum[tl] = stkl[tl] + sum[tl - 1];
    f[tl] = max(f[tl - 1], sum[tl]);
}
int main()
{
    f[0] = -0x3f3f3f3f;
    char op[2];
    int m;
    cin >> m;
    while (m--)
    {
        int x;
        scanf("%s",op);
        if (*op == 'I')
        {
            cin >> x;
            push_l(x);
        }
        else if (*op == 'D')
        {
            if (tl)
                tl--;
        }
        else if (*op == 'L')
        {
            if (tl)
            {
                stkr[++tr] = stkl[tl--];
            }
        }
        else if (*op == 'R')
        {
            if (tr)
            {
                push_l(stkr[tr--]);
            }
        }
        else if (*op == 'Q')
        {
            cin >> x;
            cout<<f[x]<<endl;
        }
    }
    return 0;
}