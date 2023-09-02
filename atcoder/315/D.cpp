#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 3000;
char g[N][N];
bool r[N], c[N];
int main()
{
    int h, w;
    cin >> h >> w;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> g[i][j];
        }
    }

    for (int i = 1; i <= h; i++)
    {
        if (r[i])
            continue;
        bool flag = false;
        char last;
        for (int j = 1; j <= w; j++)
        {
            if (!c[j])
            {
                if (g[])
            }
        }
    }
    return 0;
}