#include <iostream>
using namespace std;

const int M = 1050;

int f[M];

int n, m, w[M], v[M];

int main()
{
    cin >> n >> m; // n:volumn,m:numbers of the object
    for (int i = 1; i <= m; ++i)
        cin >> v[i] >> w[i];
    for (int i = 1; i <= m; i++)
    {
        for (int j = n; j >= v[i]; j--)
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    std::cout << f[n] << endl;
    return 0;
}