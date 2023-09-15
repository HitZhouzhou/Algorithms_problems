#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define FT(A, B, C) for (int A = B; A <= C; A++)
using namespace std;
const int N = 100005;
struct minister
{
    int l, r, rank;
    // 这里通过rank来确定大臣们的顺序 也就是贪心的部分
    //    若 a[i].l / a[j].r < a[j].l / a[i].r 可以判断 i 放在 j 的前面可以使答案更小
    //       a[i].l * a[i].r < a[j].l * a[j].r（上式化简）
    minister() {}                                                     // 没有这行会报错
    minister(int a, int b) : l(a), r(b), rank(a * b) {}               // 结构体的初始化
    bool operator<(const minister &x) const { return rank < x.rank; } // 定义一下大小规则
    // 等会直接 sort
} a[N];
struct int_l
{
    int data[N];
    int_l()
    { // 初始化
        memset(data, 0, sizeof(data));
        data[0] = 1; // data[0]中存的是位数
    }
    int_l(int x)
    { // 用低精数 初始化（赋值） 高精数
        memset(data, 0, sizeof(data));
        data[0] = 1; // 当x在(0,9)中时,data[0]=1
        int i = 1;
        while (x)
        {
            data[i++] = x % 10;
            x /= 10;
        }
        data[0] = --i; // 这里位数不能错
    }
    int_l operator*(const int &x) // 高进度*低精度
    {                             // 很普通的重载 *号
        int_l a;
        int len;
        a.data[0] = data[0];
        FT(i, 1, data[0])
        a.data[i] = data[i] * x; // 全部乘完后再进位.
        for (int i = 1; i <= a.data[0] || a.data[i]; len = ++i)
        {
            a.data[i + 1] += a.data[i] / 10;
            a.data[i] %= 10;
        }
        a.data[len] ? a.data[0] = len : a.data[0] = --len;
        return a;
    }
    int_l operator/(const int &x)
    { // 高精除低精
        int_l a;
        a.data[0] = data[0];
        int rest = 0;
        for (int i = data[0]; i >= 1; i--)
        { // 注意要从最高位开始模拟
            rest = rest * 10 + data[i];
            a.data[i] = rest / x;
            rest %= x;
        }
        while (!a.data[a.data[0]] && a.data[0] > 1)
            a.data[0]--; // 去掉多余的 0
        return a;
    }
    bool operator<(const int_l &x) const
    { // 重载 <号
        if (data[0] == x.data[0])
        { // 从位数开始比较
            int i;
            for (i = data[0]; data[i] == x.data[i] && i > 1; i--)
                ; // 然后是最高位
            if (i >= 1)
                return data[i] < x.data[i];
            else
                return false;
        }
        else
            return data[0] < x.data[0];
    }
};
ostream &operator<<(ostream &out, const int_l &x)
{
    FT(i, 1, x.data[0])
    out << x.data[x.data[0] - i + 1];
    return out;
}

int n, x, y;
int_l ans;
// int_l X,Y;
int main()
{
    //    while (1){  Debug
    //        int x,y;
    //        cin >> x >> y;
    //        X = x;
    //        Y = y;
    //        cout << (X*y) << endl;
    //        cout << (X / y) << endl;
    //        cout << (X < Y) << endl;
    //    }
    ios::sync_with_stdio(false);
    cin >> n;
    FT(i, 0, n)
    {
        cin >> x >> y;
        a[i] = minister(x, y);
    }
    sort(a + 1, a + n + 1);
    int_l k(1);
    FT(i, 1, n)
    { // 很简单的模拟
        if (a[i - 1].l == 0)
            break; // 判 0
        k = k * a[i - 1].l;
        int_l temp; // 注意被除数用temp 存下来
        // 如有大臣 防止商为0 后 k无法更新
        temp = k / a[i].r;
        if (ans < temp)
            ans = temp;
    }
    cout << ans << endl;
    return 0;
}