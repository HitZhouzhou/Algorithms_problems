#include <iostream>
using namespace std;
const int N = 100010;
bool st[N];
int n, cnt, primes[N];
void get_primes(int x)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; j < n / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j])
                break;
        }
    }
}
int main()
{
    cin >> n;
    get_primes(n);
    cout << cnt;
    return 0;
}