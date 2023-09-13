#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
struct Range
{
    int x, y;
    bool operator<(Range &w)
    {
        return y < w.y;
    }
} range[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> range[i].x >> range[i].y;
    }
    int last = -3e9;
    int cnt = 0;
    sort(range, range + n);
    for (int i = 0; i < n; i++)
    {
        if (range[i].x > last)
        {
            cnt++;
            last = range[i].y;
        }
    }
    cout << cnt << endl;
    return 0;
}