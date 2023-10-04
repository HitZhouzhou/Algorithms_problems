#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
char map[6][6], backup[6][6];
int H[37];
int lowbit(int x)
{
    return x & -x;
}
void click(int x, int y)
{
    int dx[] = {0, 0, 0, 1, -1}, dy[] = {0, 1, -1, 0, 0};
    for (int i = 0; i < 5; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
        {
            map[nx][ny] = '0' + !(map[nx][ny] - '0');
        }
    }
}
int main()
{
    int m;
    cin >> m;
    for (int i = 0; i < 36; i++)
        H[(1ll << i) % 37] = i;
    while (m--)
    {
        for (int i = 0; i < 5; i++)
        {
            cin >> map[i];
        }
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < 1 << 5; i++)
        {
            memcpy(backup, map, sizeof backup);
            int sum = 0;
            for (int j = i; j; j -= lowbit(j))
            {
                int x = lowbit(j);
                click(0, H[x % 37]);
                sum++;
            }
            for (int j = 1; j <= 4; j++)
            {
                for (int k = 0; k < 5; k++)
                {
                    if (map[j - 1][k] == '0')
                    {
                        sum++;
                        click(j, k);
                    }
                }
            }
            bool flag = true;
            for (int j = 0; j < 5; j++)
            {
                if (map[4][j] == '0')
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans = min(sum, ans);
            memcpy(map, backup, sizeof backup);
        }
        if (ans <= 6)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
