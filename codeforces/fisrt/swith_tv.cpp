#include <iostream>
using namespace std;
int jump(int p, int u, int k)
{
    int dis = abs(u - p);
    int tmp = dis / k;
    int time1 = tmp + dis % k;
    int time2 = dis / k + 1 + (dis / k + 1) * k - dis;
    return min(time1, time2);
}
int get_min(int a, int b, int c)
{
    a = min(a, b);
    c = min(a, c);
    return c;
}
int main()
{
    int n, k, p, u;
    cin >> n >> k >> p >> u;
    int t1 = (p - 1) / k + 1, t2 = (n - p) / k + 1;
    int m1 = jump(p, u, k);
    int m2 = jump(0, u, k) + t1;
    int m3 = jump(n, u, k) + t2;
    cout << get_min(m1, m2, m3);
    return 0;
}