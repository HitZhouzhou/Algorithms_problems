#include <iostream>
using namespace std;
const int N = 6e5 + 10;
int a[N], n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i + n] = a[i];
    }
    int i = 1, j = 2, k;
    while (i <= n && j <= n)
    {
        for (k = 0; k < n && a[i + k] == a[j + k]; k++)
            ;
        if (k == n)
            break;
        if (a[i + k] > a[j + k])
        {
            i = i + k + 1;
            if (i == j)
                i = i + 1;
        }
        else
        {
            j = j + k + 1;
            if (i == j)
                j = j + 1;
        }
    }
    int ans = min(i, j);
    for (i = 1; i <= n; i++)
    {
        cout << a[i + ans-1] << ' ';
    }
    cout << endl;
    return 0;
}