#include <iostream>

#include <algorithm>
#include <cstring>
using namespace std;
const int N = 100000;
int f[N], a[N], b[N], t, sum;
int main()
{
    for (int i = 0; i < 4; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < a[i]; j++)
        {
            cin >> b[j];
            sum += b[j];
        }
    
        sort(b, b + a[i]);
        for (int h = 0; h < a[i]; h++)
        {
            for (int k = sum / 2; k >= b[h]; k--)
            {

                f[k] = max(f[k], f[k - b[h]] + b[h]);
            }
        }
        t += sum - f[sum / 2];
        memset(f, 0, sizeof(f));
        memset(b, 0, sizeof(b));
        sum = 0;
    }
    cout << t << endl;
    return 0;
}