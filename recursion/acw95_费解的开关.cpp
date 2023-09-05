#include <iostream>
#include <cstring>
using namespace std;
const int N = 10;
char g[N][N];

void turn(int i, int j)
{
    int dx[] = {0, 1, -1, 0, 0}, dy[] = {0, 0, 0, 1, -1};
    for (int k = 0; k < 5; k++)
    {
        int x = i + dx[k], y = j + dy[k];
        if (x >= 0 && x < 5 && y >= 0 && y < 5)
        {
            g[x][y] ^= 1;
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < 5; i++)
            cin >> g[i];
        char backup[N][N];
        memcpy(backup, g, sizeof g);

        for (int i = 0; i < 1 << 5; i++)
        {
            int step = 0;

            for (int j = 0; j < 5; j++)
            {
                if (i >> j & 1)
                {
                    turn(0, j);
                    step++;
                }
            }
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (g[i][j] == '0')
                    {
                        turn(i + 1, j);
                        step++;
                    }
                }
            }
            bool isSuccess = true;
            for (int i = 0; i < 5; i++)
            {
                if (g[4][i] == '0')
                {
                    isSuccess = false;
                    break;
                }
            }
            if (isSuccess)
            {
                ans = min(ans, step);
            }
            memcpy(g, backup, sizeof backup);
        }
        if (ans > 6)
            ans = -1;
        cout << ans << endl;
    }
    return 0;
}