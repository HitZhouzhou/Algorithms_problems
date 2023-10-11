#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
string s;
stack<int> nums;
stack<char> ops;
typedef long long LL;
void cal()
{
    char ch = ops.top();
    ops.pop();
    int a = nums.top();
    nums.pop();
    int b = nums.top();
    nums.pop();
    int d;
    if (ch == '+')
        d = b + a;
    else if (ch == '-')
        d = b - a;
    else if (ch == '*')
        d = b * a;
    else if (ch == '/')
        d = b / a;
    else
    {
        d = 1;
        while (a--)
        {
            d *= b;
        }
    }
    nums.push(d);
}
int main()
{
    cin >> s;
    string left;
    if (s[0] == '-')
        s = '0' + s;
    for (int i = 0; i < s.size(); i++)
        left += '(';
    s = left + s + ')';
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (ch >= '0' && ch <= '9')
        {
            int t = 0, j = i;
            while (s[j] >= '0' && s[j] <= '9')
            {
                t = t * 10 + s[j] - '0';
                j++;
            }
            i = j - 1;
            nums.push(t);
        }

        else if (ch == '+' || ch == '-')
        {
            if (ch == '-' && i > 0 && !((s[i - 1] >= '0' && s[i - 1] <= '9') || s[i - 1] == ')'))
            {
                if (s[i + 1] == '(')
                {
                    nums.push(-1);
                    ops.push('*');
                }
                else
                {
                    int t = 0, j = i + 1;
                    while (s[j] >= '0' && s[j] <= '9')
                    {
                        t = t * 10 + s[j] - '0';
                        j++;
                    }
                    nums.push(-t);
                    i = j - 1;
                }
            }
            else
            {
                while (ops.size() && ops.top() == '+' || ops.top() == '-' || ops.top() == '*' || ops.top() == '/' || ops.top() == '^')
                    cal();
                ops.push(ch);
            }
        }
        else if (ch == '*' || ch == '/')
        {
            while (ops.size() && ops.top() == '*' || ops.top() == '/' || ops.top() == '^')
            {
                cal();
            }
            ops.push(ch);
        }
        else if (ch == '^')
        {
            while (ops.size() && ops.top() == '^')
            {
                cal();
            }
            ops.push(ch);
        }
        else if (ch == '(')
        {
            ops.push(ch);
        }
        else if (ch == ')')
        {
            while (ops.top() != '(')
                cal();
            ops.pop();
        }
    }
    while (ops.size())
    {
        if (ops.top() == '(')
            ops.pop();
        else
            cal();
    }
    cout << nums.top() << endl;
    return 0;
}