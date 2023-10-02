#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
string s;
int len, answer = 1010580540, st; // 1010580540是标记，见下
long long n;
void dfs(int c, int x, long long ans) // c是阶段，x是位置，ans是目前总和
{
    if (ans == n && x == len)
    {
        answer = min(answer, c - 1); // 减一是因为“小学植树问题”，阶段数减一是加号数
        return;
    }
    for (int k = 1; k + x <= len; k++) // 剪枝,k是此阶段的长度,当然,k+x必须不能大于总长度!!!
    {
        long long sum = 0; // 初值
        for (int i = x; i < k + x; i++)
            sum = sum * 10 + (s[i] - '0'); // 我没用前缀和(汗,但数据水,不用也行
        if (sum + ans <= n)                // 稍微减个枝
            dfs(c + 1, k + x, ans + sum);  // 这里的意思是，c往下一个阶段前进，位置更新为下一个加号的位置，目前总和理所当然地加上这一阶段的数值
        else
            return;
        // 既然k到这里都大于n了,在加肯定也大于...
    }
}

int main()
{
    cin >> s; // 要用cin要用cin要用cin
    len = s.length();
    scanf("%lld", &n);
    dfs(0, 0, 0);
    if (answer == 1010580540)
        answer = -1; // 组合不了
    printf("%d", answer);
    return 0;
}