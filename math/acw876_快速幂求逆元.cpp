#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
int qmi(int a, int b, int p)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (LL)res * a % p;
        a = (LL)a * a % p;
        b >>= 1;
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, p;
        cin >> a >> p;
        int res = qmi(a, p - 2, p);
        if (a % p == 0)
            puts("impossible");
        else
            cout << res << endl;
    }
    return 0;
}