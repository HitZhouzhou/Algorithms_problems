#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
const int N = 3e5 + 1000;
typedef pair<int, int> PII;
PII a[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i].first = x + y;
        a[i].second = y;
    }
    int res = -1e8, sum = 0;
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        sum -= a[i].second;
        res = max(sum, res);
        sum += a[i].first;
    }
    cout << res << endl;
    return 0;
}