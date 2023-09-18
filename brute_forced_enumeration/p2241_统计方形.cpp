#include <iostream>
#include <algorithm>
using namespace std;
const int N = 5100;
int main()
{
    int t1, t2;
    cin >> t1 >> t2;
    int n = min(t1, t2);
    int m = max(t1, t2);
    long long cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == j)
                cnt1 += ((n - i) * (m - j));
            else
                cnt2 += (n - i) * (m - j);
        }
    }
    cout << cnt1 << ' ' << cnt2 << endl;
    return 0;
}