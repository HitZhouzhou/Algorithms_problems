#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e4;
int a[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int last = a[1];
    for (int i = 2; i <= n; i++)
    {
        if (a[i] - last > 1)
        {
            cout << a[i] - 1;
            return 0;
        }
        else
            last = a[i];
    }
    return 0;
}