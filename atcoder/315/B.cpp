#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e3;
int m, d[N], sum;
int main()
{
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> d[i];
        sum += d[i];
    }
    int k = (sum + 1) / 2;
    int ad, am;
    for (int i = 1; i <= m; i++)
    {
        am = i;
        if (k <= d[i])
        {
            ad = k;
            break;
        }
        k -= d[i];
    }
    cout << am << ' ' << ad << endl;
    return 0;
}