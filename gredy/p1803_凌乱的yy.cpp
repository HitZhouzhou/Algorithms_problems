#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e6 + 1000;
typedef pair<int, int> PII;
PII a[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].second >> a[i].first; // second:left
    }
    sort(a, a + n);
    int lastr = -1e8, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].second >= lastr)
        {
            cnt++;
            lastr = a[i].first;
        }
    }
    cout << cnt << endl;
    return 0;
}