#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N = 1e5 + 100;
int a[N], n, f[N];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    f[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] <= a[i - 1])
        {
            f[i] = f[i - 1];
        }
        else
            f[i] = f[i - 1] + a[i] - a[i - 1];
    }
    cout << f[n - 1];
    return 0;
}