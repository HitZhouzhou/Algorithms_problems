#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <cstring>
using namespace std;
void bfs(string a)
{
    string end = "123804765";
    if (a == end)
    {
        cout << 0 << endl;
        return;
    }
    unordered_map<string, int> d;
    queue<string> q;
    q.push(a);
    d[a] = 0;
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        int distance = d[t];
        int idx = t.find('0');
        int x = idx / 3, y = idx % 3;
        int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++)
        {
            int rx = x + dx[i], ry = y + dy[i];
            if (rx >= 0 && rx < 3 && ry >= 0 && ry < 3)
            {
                int tidx = rx * 3 + ry;
                swap(t[idx], t[tidx]);
                if (!d.count(t))
                {
                    d[t] = distance + 1;
                    q.push(t);
                    if (t == end)
                    {
                        cout << d[t] << endl;
                        return;
                    }
                }
                swap(t[idx], t[tidx]);
            }
        }
    }
    cout << -1 << endl;
    return;
}
int main()
{
    string a;
    cin >> a;
    bfs(a);
}