#include <iostream>
#include <cstring>
using namespace std;
const int N = 1100, M = 20;
char a[N][M];
int f[N][N];
int minEdit(char c[], char d[])
{
    int lc = strlen(c + 1), ld = strlen(d + 1);
    for (int i = 1; i <= lc; i++)
    {
        f[i][0] = i;
    }
    for (int j = 1; j <= ld; j++)
    {
        f[0][j] = j;
    }
    for (int i = 1; i <= lc; i++)
    {
        for (int j = 1; j <= ld; j++)
        {
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            if (c[i] == d[j])
                f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            else
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
        }
    }
    return f[lc][ld];
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] + 1;
    }
    while (m--)
    {
        int x = 0, count = 0;
        char b[M];
        cin >> b + 1 >> x;
        for (int i = 1; i <= n; i++)
        {
            if (minEdit(a[i], b) <= x)

                count++;
        }
        cout << count << endl;
    }
    return 0;
}