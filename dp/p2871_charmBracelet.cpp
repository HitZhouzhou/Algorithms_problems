#include <iostream>
using namespace std;
const int N = 3500;

int v[N], w[N];
int f[N];

int main()
{
    int m, n;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= w[i]; j--)
        {
            f[j] = max(f[j], f[j - w[i]] + v[i]);
        }
    }
    cout << f[m];
    return 0;
}