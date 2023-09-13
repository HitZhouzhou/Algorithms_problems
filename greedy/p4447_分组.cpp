#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
const int N = 2 * 1e6 + 10;
const int M = 1e9 + 1;
typedef long long LL;
map<int, int> m;
typedef map<int, int>::iterator it;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        m[x]++;
    }
    int res = N;
    while (!m.empty())
    {
        it i = m.begin(), j = m.begin();
        --(*i).second;
        int len = 1;
        for (++j; j != m.end() && (*j).first == (*i).first + 1 && (*j).second >= (*i).second; ++i, ++j)
        {
            --(*j).second;
            len++;
        }
        i = m.begin();
        while (i != m.end() && (*i).second == 0)
        {
            m.erase((*i++).first);
        }
        res = min(len, res);
    }
    cout << res << endl;
    return 0;
}