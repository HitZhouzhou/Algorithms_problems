#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
const int N = 1010;
int n;
PII p[N];
vector<int> mul(vector<int> a, int b)
{
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i++)
    {
        t += a[i] * b;
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
vector<int> max_vec(vector<int> a, vector<int> b)
{
    if (a.size() > b.size())
        return a;
    if (a.size() < b.size())
        return b;
    if (vector<int>(a.rbegin(), a.rend()) > vector<int>(b.rbegin(), b.rend()))
        return a;
    else
        return b;
}
int main()
{
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        p[i] = {l * r, l};
    }
    sort(p + 1, p + n + 1);
    vector<int> product(1, 1);
    vector<int> res(1, 0);
    for (int i = 0; i <= n; i++)
    {
        if (i)
            res = max_vec(res, div(product, p[i].first / p[i].second));
        product = mul(product, p[i].second);
    }
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i];
    cout << endl;
    return 0;
}