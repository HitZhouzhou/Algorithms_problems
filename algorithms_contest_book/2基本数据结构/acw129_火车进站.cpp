#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 25;
int stk[N], n, tt = 0;
vector<int> path;
int remain = 0;
void dfs(int u)
{
    if (remain >= 20)
        return;
    if (u == n + 1)
    {
        remain++;
        for (int x : path)
        {
            cout << x;
        }
        for (int i = tt; i; i--)
        {
            cout << stk[i];
        }
        puts("");
        return;
    }
    if (tt)
    {
        path.push_back(stk[tt--]);
        dfs(u);
        stk[++tt] = path.back();
        path.pop_back();
    }
    stk[++tt] = u;
    dfs(u + 1);
    tt--;
}
int main()
{
    cin >> n;
    dfs(1);
    return 0;
}