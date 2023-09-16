#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        LL x, y, z;
        cin >> x >> y >> z;
        cout << ((z - y) / x) * x + y << endl;
        ;
    }
    return 0;
}