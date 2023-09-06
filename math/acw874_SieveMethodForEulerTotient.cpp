#include <iostream>
using namespace std;
const int N = 1000100;
bool st[N];
long long phi[N], primes[N], cnt;
void get_euler(int x)
{
    phi[1] = 1;
    for (int i = 2; i <= x; i++)
    {
        if (!st[i])
        {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] <= x / i; j++)
        {
            st[i * primes[j]] = true;
            if (i % primes[j] == 0) // i能整除primes[j],说明primes[j+1]不是primes[j+1]*i的最小质因子
            // primes[j]是i的最小质因子
            {
                phi[primes[j] * i] = phi[i] * primes[j];
                break;
            }
            else
                phi[primes[j] * i] = phi[i] * (primes[j] - 1);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    get_euler(n);
    long long res = 0;
    for (int i = 1; i <= n; i++)
        res += phi[i];
    cout << res << endl;
    return 0;
}