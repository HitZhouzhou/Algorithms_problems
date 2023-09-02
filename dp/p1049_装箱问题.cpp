#include <iostream>
using namespace std;
const int N = 50000;
long long f[N];
// 每个物体的价值为vi,体积为vi
long long m, n, v[N];
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= v[i]; j--)
        {
            f[j] = max(f[j], f[j - v[i]] + v[i]);
        }
    }
    cout << m - f[m] << endl;
    return 0;
}