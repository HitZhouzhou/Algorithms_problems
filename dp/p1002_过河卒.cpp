#include <iostream>
#include <cstring>
using namespace std;
const int N = 50;
/*
f[i][j]=(0,0)->(i,j)的路径数,f[i][j]=f[i-1][j]+f[i][j-1](check())
*/
int x1, y1, x2, y2;
int dx[] = {-1, 1, -1, 1, -2, 2, -2, 2}, dy[] = {-2, 2, 2, -2, 1, -1, -1, 1};
int vis[N][N];
long long f[N][N];
bool check(int x, int y)
{
    if (x == x2 && y == y2)
        return false;
    for (int i = 0; i < 8; i++)
    {
        int xx = x2 + dx[i], yy = y2 + dy[i];
        if (x == xx && y == yy)
        {
            return false;
        }
    }
    return true;
}
// 更新f(x,y)
int main()
{
    cin >> x1 >> y1 >> x2 >> y2;
    x1++, y1++, x2++, y2++;
    f[1][1] = 1;
    for (int i = 1; i <= x1; i++)
    {
        for (int j = 1; j <= y1; j++)
            if (!check(i, j))
                vis[i][j] = 1;
    }
    for (int i = 1; i <= x1; i++)
    {
        for (int j = 1; j <= y1; j++)
            if ((i != 1 || j != 1) && !vis[i][j])
                f[i][j] = f[i - 1][j] + f[i][j - 1];
    }
    cout << f[x1][y1];
    return 0;
}