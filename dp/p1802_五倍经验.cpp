#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1e4;
typedef long long LL;
typedef pair<LL, LL> pll;
vector<pll> v, w;
LL f[N], ff[N];
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int lose, win, cost;
        cin >> lose >> win >> cost;
        v.push_back({lose, 0});
        w.push_back({win, cost});
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            if (j >= w.at(i).second)
                f[j] = max(f[j] + v.at(i).first, f[j - w.at(i).second] + w.at(i).first);
            else
                f[j] += v.at(i).first;
        }
    }
    cout << f[m] * 5ll << endl;
    return 0;
}