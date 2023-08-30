#include <iostream>
#include <cstring>

using namespace std;
const int N = 1e6 + 100;
int h[N], e[N], ne[N], idx, ans = N, n;
bool state[N];
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int dfs(int u)
{
    state[u] = true;
    int sum = 1;
    int res = 0;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!state[j])
        {
            // state[i] = true;
            int s = dfs(j);
            sum += s;
            res = max(res, s);
        }
    }
    res = max(res, n - sum);
    ans = min(res, ans);
    return sum;
}
int main()
{
    memset(h, -1, sizeof(h));
    cin >> n;
    int a, b;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}