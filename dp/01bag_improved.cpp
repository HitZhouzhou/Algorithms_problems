#include <iostream>
using namespace std;
const int N = 1004;
int f[N];
int v[N], w[N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= v[i]; j--)
        {
            // f[i][j]=f[i-1][j];
            f[j] = max(f[j], f[j - v[i]] + w[i]);
            // f[i][j]=max(f[i][j],f[i-1][j-v[i]]+w[i]);
        }
    }
    cout << f[m];
    return 0;
}