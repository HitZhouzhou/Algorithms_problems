#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
const int N = 1e6 + 100;
int a[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int res = 0;
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        res += abs(a[i] - a[n >> 1]);
    }
    cout << res;
    return 0;
}