#include <iostream>
#include <algorithm>
using namespace std;
vector<int> mul(vector<int> a, int b)
{
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t += (a[i] * b);
        c.push_back(t % 10);
        t /= 10;
    }
    while (t)
    {
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}
vector<int> div(vector<int> a, int b)
{
    vector<int> c;
    bool is_first = true;
    for (int i = a.size() - 1, t = 0; i >= 0; i--)
    {
        t = t * 10 + a[i];
        int x = t / b;
        if (!is_first || x)
        {
            is_first = false;
            c.push_back(x);
        }
        t %= b;
    }
    reverse(c.begin(), c.end());
    return c;
}
int main()
{
    int n;
    cin >> n;
    vector<int> ans(1, 1);
    for (int i = 1; i <= 2 * n; i++)
    {
        ans = mul(ans, i);
    }
    for (int i = 1; i <= n; i++)
    {
        ans = div(ans, i);
        ans = div(ans, i);
    }
    ans = div(ans, n + 1);
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}