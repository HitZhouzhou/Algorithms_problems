#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> g[14];
int open[14];
int touch(int x)
{
    int ans;
    ans = g[x].back();
    g[x].pop_back();
    open[ans]++;
    return ans;
}
int main()
{
    for (int i = 1; i <= 13; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            char x[2];
            cin >> x;
            if (*x == 'A')
                g[i].push_back(1);
            else if (*x == 'J')
                g[i].push_back(11);
            else if (*x == 'Q')
                g[i].push_back(12);
            else if (*x == 'K')
                g[i].push_back(13);
            else if(*x=='0')
                g[i].push_back(10); 
            else
                g[i].push_back(*x - '0');
        }
    }

    for (int i = 0; i < 4; i++)
    {
        int x = g[13][i];
        open[x]++;
        while (x != 13)
        {
            x = touch(x);
        }
    }
    int ans = 0;
    for (int i = 1; i <= 12; i++)
    {
        if (open[i] == 4)
            ans++;
    }
    cout << ans << endl;
    return 0;
}