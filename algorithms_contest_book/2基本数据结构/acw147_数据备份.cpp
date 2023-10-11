#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<LL, int> PLI;
int n, k;
const int N = 1e5 + 10;
int l[N], r[N];
LL d[N];
void delete_node(int x)
{
    l[r[x]] = l[x];
    r[l[x]] = r[x];
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> d[i];
    for (int i = n - 1; i > 0; i--)
        d[i] -= d[i - 1];
    d[0] = d[n] = 1e15;
    set<PLI> s;
    for (int i = 1; i <= n - 1; i++)
    {
        l[i] = i - 1;
        r[i] = i + 1;
        s.insert({d[i], i});
    }
    LL ans = 0;
    while (k--)
    {
        auto t = s.begin();
        LL v = t->first;
        int p = t->second;
        int left = l[p], right = r[p];
        delete_node(left), delete_node(right);
        s.erase({d[left], left});
        s.erase({d[right], right});
        s.erase(t);
        ans += v;
        d[p] = d[left] + d[right] - d[p];
        s.insert({d[p], p});
    }
    cout<<ans<<endl;
    return 0;
}