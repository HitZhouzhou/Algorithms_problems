#include <iostream>
#include <vector>
using namespace std;

const int N = 1e6 + 10;
int f[N];
struct flower
{
    int v;
    int w;
};
vector<flower> flowers;
int a1, a2, b1, b2, n;
int main()
{
    scanf("%d:%d %d:%d %d", &a1, &a2, &b1, &b2, &n);
    int m = (b1 - a1) * 60 + b2 - a2;
    for (int i = 1; i <= n; i++)
    {
        int v, w, p;
        cin >> w >> v >> p;
        if (p == 1)
        {
            flowers.push_back({v, w});
        }
        else
        {
            if (p == 0)
                p = 9999;
            for (int k = 1; k <= p; k *= 2)
            {
                flowers.push_back({v * k, w * k});
                p -= k;
            }
            if (p > 0)
            {
                flowers.push_back({v * p, w * p});
            }
        }
    }
    for (int i = 0; i < flowers.size(); i++)
    {
        for (int j = m; j >= flowers[i].w; j--)
        {
            f[j] = max(f[j], f[j - flowers[i].w] + flowers[i].v);
        }
    }
    cout << f[m];
    return 0;
}