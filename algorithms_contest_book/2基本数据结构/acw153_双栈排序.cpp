#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
const int N = 1010;
bool g[N][N];
int f[N], a[N], n, color[N];
bool dfs(int u, int c)
{
    color[u] = c;
    for (int i = 1; i <= n; i++)
    {
        if (g[u][i])
        {
            if (color[i] == c)
                return false;
            if (color[i] == -1 && !dfs(i, !c))
                return false;
        }
    }
    return true;
}
int main()
{
    cin >> n;
    memset(color, -1, sizeof color);
    memset(g, false, sizeof g);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    f[n + 1] = n + 1;
    for (int i = n; i >= 1; i--)
        f[i] = min(a[i], f[i + 1]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[i] < a[j] && a[i] > f[j + 1])
            {
                g[i][j] = true, g[j][i] = true;
            }
        }
    }
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1 && !dfs(i, 0))
        {
            flag = false;
            break;
        }
    }
    if (!flag)
    {
        cout << 0 << endl;
        return 0;
    }
    stack<int> stk1, stk2;
    int now = 1;
    int j=1;
    for (int i = 1; i <= 2*n; i++)
    {
        if(j<=n&&color[j]==0&&(!stk1.size()||(stk1.size()&&stk1.top()>a[j])))
        {
            stk1.push(a[j]);
            j++;
            cout<<"a ";
        }
        else if(stk1.size()&&stk1.top()==now)
        {
            stk1.pop();
            cout<<"b ";
            now++;
        }
        else if(j<=n&&color[j]==1&&(!stk2.size()||stk2.size()&&stk2.top()>a[j]))
        {
            stk2.push(a[j]);
            j++;
            cout<<"c ";
        }
        else
        {
            stk2.pop();
            now++;
            cout<<"d ";
        }
    }

    cout << endl;
    return 0;
}