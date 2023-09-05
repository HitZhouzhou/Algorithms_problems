#include <iostream>
#include <string>
using namespace std;
const int N = 100;
int path[N], st[N];
int n, m;
void dfs(int start, int sum, int state)
{
    if (sum == m)
    {
        for (int j = 0; j < n; j++)
        {
            if (state >> j & 1)
            {
                cout << j + 1 << ' ';
            }
        }
        cout << endl;
        return;
    }
    if (n - start + sum < m || start > n)
        return;
    dfs(start + 1, sum + 1, state + (1 << start));
    dfs(start + 1, sum, state);
}
int main()
{
    cin >> n >> m;
    dfs(0, 0, 0);
    return 0;
}