#include <iostream>
using namespace std;
typedef long long LL;
LL res;
void qmi(LL a, LL b, LL p)
{
    res = 1;
    while (b)
    {
        if (b & 1)
            res = (LL)(res * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
}
void quick_m(LL a, LL b, LL p)
{
    res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = res * a % p;
        }
        a = (a * a) % p;
        b >>= 1;
    }
}
int main()
{
    LL t;
    cin >> t;
    LL a, b, p;
    while (t--)
    {
        cin >> a >> b >> p;
        qmi(a, b, p);
        cout << res << endl;
    }

    return 0;
}