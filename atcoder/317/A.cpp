#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e4;
int a[N];
int main()
{
    int n, h, x;
    cin >> n >> h >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= x - h)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}