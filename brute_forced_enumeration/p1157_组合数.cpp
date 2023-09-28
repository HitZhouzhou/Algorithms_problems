#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
using namespace std;
int a, b, c;
const int N = 25;
int p[N], st[N];
void dfs(int u)
{
    if (u == b + 1)
    {
        for (int i = 1; i <= b; i++)
        {
            cout << setw(3) << p[i];
        }
        cout << endl;
    }
    for (int i = p[u - 1] + 1; i <= a; i++)
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
    cin >> a >> b;
    if (b == 0)
    {
        return 0;
    }
    dfs(1);
    return 0;
}