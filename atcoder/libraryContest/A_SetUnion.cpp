#include <iostream>
using namespace std;
const int N = 2 * 1e6 + 100;
int p[N];
int find(int x)
{
    if (p[x] != x)
    {
        p[x] = find(p[x]);
    }
    return p[x];
}
int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
    }
    while (q--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 0)
        {
            p[find(x)] = find(y);
        }
        if (op == 1)
        {
            if (find(x) == find(y))
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
    }
    return 0;
}