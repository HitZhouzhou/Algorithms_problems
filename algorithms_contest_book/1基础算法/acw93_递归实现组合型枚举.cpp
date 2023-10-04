#include <iostream>
#include <cstring>
#include<vector>
using namespace std;
int n, m;
vector<int> chosen;
void cal(int u)
{
    if (chosen.size() > m || chosen.size() + u < m)
        return;
    if (u == 0)
    {
        for (int i = chosen.size()-1; i >=0; i--)
        {
            printf("%d ", chosen[i]);
        }
        puts("");
    }
    cal(u-1);
    chosen.push_back(u);
    cal(u-1);
    chosen.pop_back();
}
int main()
{
    cin >> n >> m;
    cal(n);
    return 0;
}