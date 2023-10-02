#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
const int N = 11;
bool st[N];
int n, p[N];
void dfs(int u)
{
    if (u == n + 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << setw(5) << p[i];
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        {
            p[u] = i;
            st[i] = true;
            dfs(u + 1);
            st[i] = false;
        }
    }
}
int main()
{
    cin >> n;
    dfs(1);
    return 0;
}