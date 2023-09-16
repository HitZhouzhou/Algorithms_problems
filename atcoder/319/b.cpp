#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string ans = "1";
    for (int i = 1; i <= n; i++)
    {
        int j;
        for (int k = 1;; k++)
        {
            if (k * n % i == 0)
            {
                j = k * n / i;
                break;
            }
        }
        if (j > 9)
            ans += "-";
        else
            ans += (char)(j + '0');
    }
    cout << ans;
    return 0;
}