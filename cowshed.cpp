#include <iostream>
#include <algorithm>
using namespace std;
const int M = 209;
bool cmp(const int x, const int y)
{
    return x > y;
}
int main()
{
    int m, b, sn;
    cin >> m >> sn >> b;
    if (m >= b)
        cout << b << endl;
    else
    {
        int distance[M];
        int bn[M];
        for (int i = 1; i <= b; i++)
        {
            cin >> bn[i];
        }
        sort(bn + 1, bn + b + 1);
        int count = (bn[b] - bn[1] + 1);
        for (int i = 1; i <= b - 1; i++)
        {
            distance[i] = bn[i + 1] - bn[i] - 1;
        }
        sort(distance + 1, distance + b, cmp);

        for (int i = 1; i <= m - 1; i++)
        {
            count -= distance[i];
        }
        cout << count << endl;
    }
    return 0;
}