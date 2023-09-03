#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    long long a, b, p;
    cin >> a >> b >> p;
    long long ans = 1 % p;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * a) % p;
        }
        b >>= 1;
        a = (a * a) % p;
    }
    cout << ans;
    return 0;
}