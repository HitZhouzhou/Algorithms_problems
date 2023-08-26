#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
typedef long long ULL;
ULL f[N];
struct good
{
    int v, w;
};
int n, m;
vector<good> goods;
int main()
{
    goods.push_back({0, 0});
    cin >> n >> m;
    while (n--)
    {
        int v, w, s;
        cin >> v >> w >> s;
        for (int k = 1; k <= s; k *= 2)
        {
            goods.push_back({v * k, w * k});
            s -= k;
        }
        if (s > 0)
            goods.push_back({v * s, w * s});
    }
    for (int i = 1; i <= goods.size(); i++)
    {
        for (int j = m; j >= goods[i].w; j--)
        {
            f[j] = max(f[j], f[j - goods[i].w] + goods[i].v);
        }
    }
    cout << f[m];
    return 0;
}