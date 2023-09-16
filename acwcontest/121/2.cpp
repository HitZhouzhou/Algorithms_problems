#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e4;
int a[N][N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    int cnt = 0;
    int res[N];
    for (int i = 1; i <= n; i++)
    {
        bool isgood = true;
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 1 || a[i][j] == 3)
            {
                isgood = false;
            }
        }
        if (isgood)
        {
            res[cnt++] = i;
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++)
    {
        cout << res[i] << ' ';
    }
    return 0;
}