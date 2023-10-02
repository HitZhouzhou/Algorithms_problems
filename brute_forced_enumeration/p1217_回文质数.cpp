#include <iostream>
#include <algorithm>
using namespace std;
int a, b;
const int N = 1e8 + 100;
int num[N];
bool isPrime(int x)
{
    for (int i = 2; i <= x / i; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cin >> a >> b;
    int cnt = 0;
    for (int d = 1; d <= 9; d += 2)
    {
        num[cnt++] = d;
    }
    for (int d = 1; d <= 9; d += 2)
    {
        num[cnt++] = d * 10 + d;
    }

    for (int d1 = 1; d1 <= 9; d1 += 2)
    { // 只有奇数才会是素数
        for (int d2 = 0; d2 <= 9; d2++)
        {
            num[cnt++] = d1 * 100 + d2 * 10 + d1;
        }
    }
    for (int d1 = 1; d1 <= 9; d1 += 2)
    {
        for (int d2 = 0; d2 <= 9; d2++)
        {
            num[cnt++] = d1 * 1000 + d2 * 100 + d2 * 10 + d1;
        }
    }
    for (int d1 = 1; d1 <= 9; d1 += 2)
    { // 只有奇数才会是素数
        for (int d2 = 0; d2 <= 9; d2++)
        {
            for (int d3 = 0; d3 <= 9; d3++)
            {
                num[cnt++] = 10000 * d1 + 1000 * d2 + 100 * d3 + 10 * d2 + d1; //(处理回文数...)
            }
        }
    }
    // 6
    for (int d1 = 1; d1 <= 9; d1 += 2)
    { // 只有奇数才会是素数
        for (int d2 = 0; d2 <= 9; d2++)
        {
            for (int d3 = 0; d3 <= 9; d3++)
            {
                num[cnt++] = 100000 * d1 + 10000 * d2 + d3 * 1000 + 100 * d3 + 10 * d2 + d1; //(处理回文数...)
            }
        }
    }
    // 7
    for (int d1 = 1; d1 <= 9; d1 += 2)
    { // 只有奇数才会是素数
        for (int d2 = 0; d2 <= 9; d2++)
        {
            for (int d3 = 0; d3 <= 9; d3++)
            {
                for (int d4 = 0; d4 <= 9; d4++)
                {
                    num[cnt++] = 1000000 * d1 + 100000 * d2 + d3 * 10000 + d4 * 1000 + 100 * d3 + 10 * d2 + d1; //(处理回文数...)
                }
            }
        }
    }
    for (int i = 0; i < cnt; i++)
    {
        if (num[i] >= a && num[i] <= b && isPrime(num[i]))
        {
            cout << num[i] << endl;
        }
    }
    return 0;
}