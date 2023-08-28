#include <iostream>

using namespace std;
const int N = 10;
int state[N], path[N];
int n;
void dfs(int u)
{
    if (u > n)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << path[i] << ' ';
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!state[i])
        {
            path[u] = i;
            state[i] = 1;
            dfs(u + 1);
            state[i] = 0;
        }
    }
}
int main()
{
    cin >> n;
    dfs(1);
    return 0;
}