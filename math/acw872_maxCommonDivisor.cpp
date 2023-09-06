#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int x, int y)
{
    while (y)
    {
        int z = x % y;
        x = y;
        y = z;
    }
    return x;
}
int main()
{
    int n;
    int x, y;
    cin >> n;
    while (n--)
    {
        cin >> x >> y;
        cout << gcd(x, y) << endl;
    }
    return 0;
}