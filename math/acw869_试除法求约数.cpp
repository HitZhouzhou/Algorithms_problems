#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void get_primes(int x)
{

    vector<int> primes;
    for (int i = 1; i <= x / i; i++)
    {
        if (x % i == 0)
        {
            primes.push_back(i);
            if (i != x / i)
                primes.push_back(x / i);
        }
    }
    sort(primes.begin(), primes.end());
    for (auto prime : primes)
    {
        cout << prime << ' ';
    }
    puts("");
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        get_primes(x);
    }
    return 0;
}