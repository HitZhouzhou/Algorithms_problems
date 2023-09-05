#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
int main()
{
    int n;
    cin >> n;
    for (LL i = 0; i < 1 << n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >> j & 1)
            {
                cout << j + 1 << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}