#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int a[14];
int match[2300];
int main()
{
    cin >> n;
    a[0] = 6, a[1] = 2, a[2] = 5, a[3] = 5, a[4] = 4, a[5] = 5, a[6] = 6, a[7] = 3, a[8] = 7, a[9] = 6;
    n = n - 4;
    match[0] = 6;
    for (int i = 1; i < 2300; i++)
    {
        int x = 0;
        int ti = i;
        while (ti)
        {
            x += a[ti % 10];
            ti /= 10;
        }
        match[i] = x;
    }
    long long ans = 0;
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {
            if (match[i] + match[j] + match[i + j] == n)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}