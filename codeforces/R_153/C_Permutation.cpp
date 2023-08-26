#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        int mn = m + 1, winmn = m + 1;
        int ans = 0;
        while (m--)
        {
            int x = 0;
            cin >> x;
            if (x > mn && x < winmn)
            {
                ans++;
                winmn = x;
            }
            mn = min(mn, x);
        }

        cout << ans << endl;
    }
    return 0;
}