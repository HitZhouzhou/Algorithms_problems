#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;
const int N = 100;
int n, idx;
bool h[N];
struct edge
{
    int x, y, w;
    bool operator<(const edge &k)
    {
        return w > k.w;
    }
} g[N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int x;
            cin >> x;
            g[idx].x = i, g[idx].y = j, g[idx++].w = x;
        }
    }
    long long ans = 0;
    for (int i = 0; i < idx - 1; i++)
    {
        for (int j = i + 1; j < idx; j++)
        {
        }
    }
    return 0;
}