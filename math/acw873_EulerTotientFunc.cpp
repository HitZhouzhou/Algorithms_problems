#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        long long res = x;
        for (int i = 2; i <= x / i; i++)
        {
            if (x % i == 0)
            {
                res = res * (i - 1) / i;
                while (x % i == 0)
                    x /= i;
            }
        }
        if (x > 1)
            res = res * (x - 1) / x;
        cout << res << endl;
    }
}