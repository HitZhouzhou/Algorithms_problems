#include <iostream>
using namespace std;
const int N = 15000000;
long long f[N];
int v[N], w[N];
int main()
{
    int t, m;
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
        cin >> w[i] >> v[i];
    for (int i = 1; i <= m; i++)
    {
        for (int j = w[i]; j <= t; j++)
        {
            f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }
    cout << f[t];
    return 0;
}