#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int n;          // 单词数
string tr[30];  // 存储字符串
int yc[30][30]; // 两个字母的最小重叠部分
int vis[30];    // 判断单词使用频率.
int mt(int x, int y)
{ // mt函数，返回x单词后连接一个y单词的最小重叠部分
    bool pp = true;
    int ky = 0;
    for (int k = tr[x].size() - 1; k >= 0; k--)
    { // 从x单词尾部向前看看最小重叠部分是从哪里开始的，以为因为是倒着来，所以保证是最小的
        for (int kx = k; kx < tr[x].size(); kx++)
        {
            if (tr[x][kx] != tr[y][ky++])
            {
                pp = false;
                break;
            }
        }
        if (pp == true)
        { // 如果说当前以k为开头的前一个单词后缀 ,是后面单词的前缀，就马上返回重叠部分。（tr[x].size()-k是找出来的规律）
            return tr[x].size() - k;
        }
        ky = 0;
        pp = true; // 不行就继续
    }
    return 0;
} // 可能这里有点难理解。可以手动模拟一下
char ch;      // 开头字母
int ans = -1; // 答案
int an = 0;   // 每次搜到的当前最长串
void dfs(int p)
{ // p为尾部单词编号(p的后缀就是“龙”的后缀，因为p已经连接到”龙“后面了)
    bool jx = false;
    for (int j = 1; j <= n; j++)
    {
        if (vis[j] >= 2)
            continue; // 使用了两次就跳过
        if (yc[p][j] == 0)
            continue; // 两单词之间没有重合部分就跳过
        if (yc[p][j] == tr[p].size() || yc[p][j] == tr[j].size())
            continue;                  // 两者存在包含关系就跳过
        an += tr[j].size() - yc[p][j]; // 两单词合并再减去最小重合部分
        vis[j]++;                      // 使用了一次
        jx = true;                     // 标记一下当前已经成功匹配到一个可以连接的部分
        dfs(j);                        // 接上去
        an -= tr[j].size() - yc[p][j]; // 回溯，就要再减回去那一部分长度
        vis[j]--;                      // 回溯,使用--
    }
    if (jx == false)
    {                       // jx==false说明不能再找到任何一个单词可以相连了
        ans = max(ans, an); // 更新ans
    }
    return;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        cin >> tr[i];
    cin >> ch;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            yc[i][j] = mt(i, j);
        }
    } // 预处理yc数组。yc[i][j]就表示，i单词后连接一个j单词的最小重叠部分
    // 比如 i表示at,j表示att. yc[i][j]就为2 但是yc[j][i]就为0.
    // 预处理是一个关键

    for (int i = 1; i <= n; i++)
    { // 从头到尾看一下有没有以指定开头字母为开头的单词
        if (tr[i][0] == ch)
        {                      // 如果有，就以当前单词为基准进行搜索。
            vis[i]++;          // 使用过一次
            an = tr[i].size(); // 更新当前串长度
            dfs(i);            // 接上
            vis[i] = 0;        // 消除影响
        }
    }
    printf("%d", ans);
    return 0;
}