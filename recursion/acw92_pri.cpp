#include <iostream>
#include <algorithm>
using namespace std;
const int N = 30;
int path[N], n;
bool state[N];
void dfs(int pos, int start, int tar)
{
    if (pos == tar + 1)
    {
        for (int i = 1; i <= tar; i++)
            cout << path[i] << ' ';
        cout << endl;
        return;
    }
    for (int i = start; i <= n; i++)
    {
        if (!state[i])
        {
            path[pos] = i;
            state[i] = true;
            dfs(pos + 1, i + 1, tar);
            state[i] = false;
        }
    }
}
int main()
{
    cout << endl;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        dfs(1, j, i);
    }
    return 0;
}