#include <iostream>
#include <cstring>
using namespace std;
const int N = 100;
int n, path[N];
void dfs(int state, int u)
{
    if (u == n)
    {
        for (int j = 0; j < n; j++)
        {
            cout << path[j] << ' ';
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        if (!(state >> i & 1))
        {
            path[u] = i + 1;
            dfs(state | 1 << i, u + 1);
        }
    }
}
int main()
{
    cin >> n;
    dfs(0, 0);
    return 0;
}