#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a, b, c;
const int N = 20;
int p[N], st[N];
bool flag = false;
void dfs(int u)
{
    if (u == 10)
    {

        int s1 = 0, s2 = 0, s3 = 0;
        for (int j = 1; j <= 3; j++)
        {
            s1 = s1 * 10 + p[j];
        }
        for (int j = 4; j <= 6; j++)
        {
            s2 = s2 * 10 + p[j];
        }
        for (int j = 7; j <= 9; j++)
        {
            s3 = s3 * 10 + p[j];
        }
        if (b * s1 == a * s2 && b * s3 == c * s2)
        {
            flag = true;
            printf("%d %d %d\n", s1, s2, s3);
        }
        return;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (!st[i])
        {
            p[u] = i;
            st[i] = 1;
            dfs(u + 1);
            st[i] = 0;
        }
    }
}
int main()
{
    cin >> a >> b >> c;
    dfs(1);
    return 0;
}