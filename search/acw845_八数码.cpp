#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;
string start;

void bfs()
{
    string end = "12345678x";
    queue<string> q;
    unordered_map<string, int> d;
    q.push(start);
    d[start] = 0;
    while (!q.empty())
    {
        string t = q.front();
        q.pop();
        int distance = d[t];
        if (t == end)
        {
            cout << distance << endl;
            return;
        }

        int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};
        int index = t.find('x');
        int lx = index / 3, ly = index % 3;
        for (int i = 0; i < 4; i++)
        {
            int x = lx + dx[i];
            int y = ly + dy[i];
            if (x >= 0 && x < 3 && y >= 0 && y < 3)
            {
                swap(t[index], t[x * 3 + y]);
                if (!d.count(t))
                {
                    q.push(t);
                    d[t] = distance + 1;
                }
                swap(t[index], t[x * 3 + y]);
            }
        }
    }
    cout << -1 << endl;
    return;
}
int main()
{
    for (int i = 0; i < 9; i++)
    {
        string tmp;
        cin >> tmp;
        start += tmp;
    }
    bfs();
    return 0;
}